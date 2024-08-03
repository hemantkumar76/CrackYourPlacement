class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
     int ans=-1;
        int m=mat.size();
        int a=0;
        int x=m;
        while(x--)
        {
            int flag1=0;
            int flag2=0;
            for(int i=0;i<m;i++)
            {
                if(i==a)continue;
                if(mat[a][i]==1)
                {
                    flag1=1;
                    break;
                }
            }
            if(flag1==0)
            {
                for(int j=0;j<m;j++)
                {
                    if(j==a)continue;
                    if(mat[j][a]==0 && j!=a)
                    {
                        flag2=1;
                        break;
                    }
                }
            }
            if(flag1==0 && flag2==0)
            {
                return a;
            }
            a++;
            
        }
        return ans;
    }
};
