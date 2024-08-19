class Solution {
public:
    int nthUglyNumber(int n) {

        vector<int> lol(n);
        // 1st ugly number hamesha 1 hoga
        lol[0] = 1;

        // 2 ke multiples ke liye pointer banate hai 
        int p1 = 0;
        // 3 ke multiples ke liye pointer banate hai 
        int p2 = 0;
        // 5 ke multiples ke liye pointer banate hai 
        int p3 = 0;
        
        // iterationc halu karte hai jo number diya hai wha tak
        for(int i=1;i<n;i++){


            int multiple_of_2 = lol[p1] * 2;
            int multiple_of_3 = lol[p2] * 3;
            int multiple_of_5 = lol[p3] * 5;
            // subbse chhota multiple choose karte hai 
            lol[i] = min(multiple_of_2, min(multiple_of_3,multiple_of_5 ));

            if(lol[i] == multiple_of_2)
            {
                p1++;
            }
            if(lol[i] == multiple_of_3)
            {
                p2++;
            } 
                
            if(lol[i] ==  multiple_of_5)
            {
                p3++;
            }
            
        }

        return lol[n-1];
        
    }
};
