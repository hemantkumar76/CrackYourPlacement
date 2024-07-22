class Solution {
public:
int n;
int solve(vector<int>&nums,int k,int idx,vector<int>&dp)
{
    // Agar idx n se bada ya barabar ho gaya toh 0 return karo
    if(idx>=n)
    {
        return 0;
    }
    // Agar dp[idx] pehle se hi calculate kiya hua hai toh wahi return karo
    if(dp[idx]!=-1)
    {
        return dp[idx];
    }
    int ans=INT_MAX;
    int sum=0;
    // idx se leke n tak ke elements pe loop chalao
    for(int i=idx;i<n;i++)
    {
        sum+=nums[i];
        // Agar k sum se bada ya barabar hai aur i last element hai toh next subproblem solve karo
        if(k>=sum && i==n-1)
        {  
           ans=min(ans,solve(nums,k,i+1,dp)); 
        }
        // Agar k sum se bada ya barabar hai toh x calculate karo aur next subproblem solve karo
        else if(k>=sum)
        {  
           int x=k-sum;
           x=x*x;
           ans=min(ans,x+solve(nums,k,i+1,dp)); 
        }
        ++sum;
    }
    // dp[idx] ki value calculate karke return karo
    return dp[idx]=ans;
}
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        // nums ka size n me store karo
        n=nums.size();
        // dp array initialise karo size n ke saath aur sabhi values -1 se
        vector<int>dp(n,-1);
        // solve function call karo aur uska result return karo
        return solve(nums,k,0,dp);
    } 
};
