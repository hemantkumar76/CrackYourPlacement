class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // count ko 0 se initialise karte hain
        int count = 0;
        // candidate ko kisi bhi element se initialise karte hain
        int candidate = 0;

        // nums ke har element ke liye
        for (int num : nums) {
            // Agar count 0 hai
            if (count == 0) {
                // Toh candidate ko num se update karte hain
                candidate = num;
            }
            // Agar num candidate ke barabar hai
            if (num == candidate) {
                // Toh count ko 1 se badhate hain
                count += 1;
            } else {
                // Varna count ko 1 se kam karte hain
                count -= 1;
            }
        }

        // candidate majority element hoga
        return candidate;
    }
};
