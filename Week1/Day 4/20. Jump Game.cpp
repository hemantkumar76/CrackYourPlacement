class Solution {
public:
    bool canJump(vector<int>& nums) {
        // pehle goal set karte hai size - 1 se 

        int goal_hai = nums.size()-1;


        // check akrne ke liye iterate karte hai 
        for(int i = nums.size()-2; i>=0; i--)
        {
            if(i+nums[i] >= goal_hai)
            {
                goal_hai = i;
            }
        }
        return goal_hai ==0;
        
    }
};
