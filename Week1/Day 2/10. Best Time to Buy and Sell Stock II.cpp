class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        // Loop through the prices from the second day
        for (int i = 1; i < prices.size(); i++) {
            // Agar aaj ka price kal se zyada hai, toh hum stock khareedte hain kal
            // Aur bechte hain aaj, aur profit mein add kar dete hain difference
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }

        // Return the total profit
        return profit;
    }
};
