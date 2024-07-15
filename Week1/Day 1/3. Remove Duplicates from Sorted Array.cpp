class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(); // Array ki size store kar rahe hain
        int k = 1; // 'k' variable hum use kar rahe hain next unique element ko place karne ke liye

        // Array ke har element ke liye loop chala rahe hain, starting from the second element
        for(int i=1; i<n; i++){
            // Agar current element aur previous element same nahi hain, toh yeh ek unique element hai
            if(nums[i] != nums[i-1]){
                // Isliye hum is element ko 'k' position pe place kar dete hain
                nums[k] = nums[i];
                // Aur 'k' ko increment kar dete hain
                k++;
            }
        }
        // Last mein, hum 'k' return kar dete hain, jo ki new length hai array ki
        return k;
    }
};
