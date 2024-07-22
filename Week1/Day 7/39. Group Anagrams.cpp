class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // lets create the map
        unordered_map<string, vector<string>> map;

        // .    .
        // .    .
        // .    .
        // .    .
        // we will start the iteration  of the array that is
        // strs = ["eat","tea","tan","ate","nat","bat"]

        for (auto x : strs) {
            // in temp all the traversed array value will be saved
            string temp = x;
            // we can sort all the characters

            // eat is there
            // it will be chased that is aet
            sort(temp.begin(), temp.end());
            // after sorting we will push back into the map

            // we will pust temp value and will replace the x
            map[temp].push_back(x);
        }

        // lets creat a vector for storing the ans
        vector<vector<string>> ans_hoga;

        // we will do iterations of the map
        // because in teh map we are having sorted string array

        for (auto x : map) {
            ans_hoga.push_back(x.second);
        }

        return ans_hoga;
    }
};
