class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // Ek unordered_map banate hain jisme hum count karenge har number ka
        unordered_map<int, int> Map;

        // Ek vector banate hain jisme hum store karenge duplicate numbers
        vector<int> ans;

        // Har number ke liye, uska count badhate hain map mein
        for(auto it : nums)
        {
            Map[it]++;
        }
        // Fir map ke har element ke liye, check karte hain ki kya uska count 2 hai
        for(auto bt : Map)
        {
            // Agar count 2 hai, toh us number ko ans vector mein daalte hain
            if(bt.second == 2)
            {
                ans.push_back(bt.first);
            }
        }
        // Ant mein, ans vector return karte hain
        return ans;
    }
};
