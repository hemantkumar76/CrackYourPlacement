class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        // we have to like return 3 random numbers fromom the given array that
        // will sum up to the target value target is 0;
        int target = 0;
        // for twor pointer our nums array would be sorted
        // lets sort the nums array
        sort(nums.begin(), nums.end());
        // lets create a vector for the answer
        vector<vector<int>> ans_hoga;

        // traversing
        for (int i = 0; i < n; i++) {
            // the value should not be equal to each other
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            // two pointer

            // first for the left side
            int j = i + 1;

            // second for the right side
            int k = n - 1;

            // [-1,0,1,2,-1,-4]
            //  i. j.        k

            // we our starting out main contiiosn that satisfy the requirments
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == target) {
                    // if our sum is equalt fo 0 then we will immd. put it into
                    // the vector
                    ans_hoga.push_back({nums[i], nums[j], nums[k]});

                    // we will increment and decrement our pointers
                    j++;
                    k--;

                    // we can now check for the duplicates
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                    //  [-1,0,1,2,-1,-4]
                    while (j < k && nums[k] == nums[k +1]) {
                        k--;
                    }

                } 
                else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return ans_hoga;
    }
};
