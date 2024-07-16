class Solution {
public:
    int reversePairs(vector<int>& nums) {
        // mergeSort function ko call karke total reverse pairs ka count
        // nikalte hain
        return mergeSort(nums, 0, nums.size() - 1);
    }

private:
    int mergeSort(vector<int>& nums, int low, int high) {
        // Agar low high se bada ya barabar hai, toh 0 return karte hain
        if (low >= high)
            return 0;
        // mid ko calculate karte hain
        int mid = low + (high - low) / 2;
        // mergeSort function ko recursively call karke low se mid tak aur
        // mid+1 se high tak ke reverse pairs ka count nikalte hain
        int count = mergeSort(nums, low, mid) + mergeSort(nums, mid + 1, high);
        // nums[i] aur nums[j] ke liye reverse pairs ka count nikalte hain
        for (int i = low, j = mid + 1; i <= mid; i++) {
            while (j <= high && nums[i] > 2LL * nums[j])
                j++;
            count += j - (mid + 1);
        }
        // nums ko low se high tak sort karte hain
        sort(nums.begin() + low, nums.begin() + high + 1);
        // Total count return karte hain
        return count;
    }
};
