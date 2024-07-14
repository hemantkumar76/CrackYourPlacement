class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(); // Array ki size store kar rahe hain
        int lol = 0; // 0s ki count ke liye
        int lol1 = 0; // 1s ki count ke liye
        int lol2 = 0; // 2s ki count ke liye

        // Pehle loop mein hum 0s, 1s, aur 2s ki count kar rahe hain
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                lol++;
            } else if (nums[i] == 1) {
                lol1++;
            }
            else 
            {
                lol2++;
            }
        }

        // Phir hum array mein pehle saare 0s daal rahe hain
        for(int i =0; i<lol; i++)
        {
            nums[i] = 0;
        }

        // Phir hum array mein saare 1s daal rahe hain
        for(int i =lol; i<lol+lol1; i++)
        {
            nums[i] = 1;
        }

        // Last mein hum array mein saare 2s daal rahe hain
        for(int i =lol+lol1; i<n; i++)
        {
            nums[i] = 2;
        }
    }
};
