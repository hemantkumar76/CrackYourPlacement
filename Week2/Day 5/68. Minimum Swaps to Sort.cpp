class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
    int minSwaps(vector<int>&nums)
    {
        int n = nums.size();
        vector<pair<int, int>> arrPos(n);
        for(int i = 0; i < n; i++) {
            arrPos[i].first = nums[i];
            arrPos[i].second = i;
        }
        
        sort(arrPos.begin(), arrPos.end());
        
        vector<bool> visited(n, false);
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(visited[i] || arrPos[i].second == i)
                continue;
                
            int cycle_size = 0;
            int j = i;
            while(!visited[j]) {
                visited[j] = 1;
                j = arrPos[j].second;
                cycle_size++;
            }
            
            if(cycle_size > 0) {
                ans += (cycle_size - 1);
            }
        }
        
        return ans;
    }
};
