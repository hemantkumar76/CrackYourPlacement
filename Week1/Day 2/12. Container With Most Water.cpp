class Solution {
public:
    int maxArea(vector<int>& height) {

        // declaring the value of n as an size of teh height array

        int n = height.size();

        // we have been given an height array
        //[1,8,6,2,5,4,8,3,7]
        // lets do with teh 2 poi ter approach

        // setting up the i pointer
        int i = 0;
        // setting up the j pointer

        int j = n - 1;

        int ans = 0;
        // lets start the traversing
        while (i < j) {
            // we will check the current area
            int area_now;

            // we will multiply with the rectangle formula ;*b

            area_now = min(height[i], height[j]) * (j - i);
            ans = max(ans, area_now);

            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return ans;
    }
};
