class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Agar array mein sirf ek element hai toh usi ko return kar do
        if (nums.size() == 1) return nums[0];

        // Do variables banate hain, ek maximum product ke liye aur ek minimum product ke liye
        long long max_product = nums[0], min_product = nums[0], result = nums[0];

        // Array ke har element pe loop chalate hain
        for (int i = 1; i < nums.size(); i++) {
            // Agar current number negative hai toh maximum aur minimum product ko swap kar dete hain
            // Kyunki negative number se multiply karne se bada number chota ho jata hai aur chota number bada
            if (nums[i] < 0) swap(max_product, min_product);

            // Maximum aur minimum product ko update karte hain
            // Ya toh current number se multiply karke ya fir current number ko naya product maan ke
            max_product = max((long long)nums[i], max_product * nums[i]);
            min_product = min((long long)nums[i], min_product * nums[i]);

            // Result ko update karte hain agar maximum product se bada ho toh
            result = max(result, max_product);
        }

        // Last mein result return kar dete hain
        return (int)result;
    }
};
