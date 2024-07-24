class Solution{
  public:
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        // Do arrays banate hain left aur right
        vector<long long int> left(n, 1), right(n, 1);

        // left[i] mein store karte hain nums[0] se nums[i-1] tak ke elements ka product
        for(int i=1; i<n; i++) {
            left[i] = nums[i-1] * left[i-1];
        }

        // right[i] mein store karte hain nums[n-1] se nums[i+1] tak ke elements ka product
        for(int i=n-2; i>=0; i--) {
            right[i] = nums[i+1] * right[i+1];
        }

        // Ab har position par, us position ke left aur right elements ka product calculate karte hain
        for(int i=0; i<n; i++) {
            nums[i] = left[i] * right[i];
        }

        // Last mein, nums array return karte hain
        return nums;
    }
};
