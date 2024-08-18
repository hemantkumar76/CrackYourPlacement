class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n = nums.size();

        // we need to create a map for storuing the values and frwq.

        unordered_map<int, int> map;
        // we will create the ans vector for returning the ans array
        vector<int> ans_hoga;

        // now we will start the traversing

        // 1,1,1,2,2,2,3,4
        for (int i = 0; i < n; i++) {
            map[nums[i]]++;
        }

        // we will sort and store it in the pair vector
        // because we have to maintain the element and freq also
        // ober declaration we can just sort also
        vector<pair<int, int>> lol(map.begin(), map.end());

        // we are just making 2 seperate maps
        sort(lol.begin(), lol.end(), [] (pair<int, int > lol1,pair <int, int > lol2) { return lol1.second > lol2.second; });
        // printing ans
        for (int i = 0; i < k; i++) { // push teh value in the ans vector
            ans_hoga.push_back(lol[i].first);
        }
        return ans_hoga;
    }
};
