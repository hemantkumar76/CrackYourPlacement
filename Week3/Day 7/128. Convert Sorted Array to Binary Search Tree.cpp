class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Hum array ke saare elements pe recursive call karte hain
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
        // agar start > end hai, toh subtree khali hai
        if (start > end) {
            return nullptr;
        }

        // Middle element ko root node banate hain
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(nums[mid]);

        // Left half ko left subtree banate hain
        node->left = sortedArrayToBST(nums, start, mid - 1);

        // Right half ko right subtree banate hain
        node->right = sortedArrayToBST(nums, mid + 1, end);

        return node;
    }
};
