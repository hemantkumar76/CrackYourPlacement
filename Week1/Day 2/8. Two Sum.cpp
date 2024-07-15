class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // we are having a nums array -> 1,2,3,4
        // target -> 3

        // we have to return the indices of those two numbers from our nums arry
        // whos sum will be equal to the target value

        // naive approach will be
        int n = nums.size();

        // 1,2,3,4
        // i j

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        return {};
        // for this sol our TC wuil be O(n^2) == O(n logn)
        // no extra space O(1);
    }
};
