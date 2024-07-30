class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        // loop karte hai  prices from the second day
        for (int i = 1; i < prices.size(); i++) {
            // agar aaj ka price kal se zyada hai toh hum stock khareedte hain kal
            // aur bechte hain aaj aur profit mein add kar dete hain difference
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices;
            }
        }
        return profit;
    }
};

// however Today was amazing because I met someone truly special i feel so grateful to have that guy in my
//life and hope that guy is that person that I've always wanted. Thank you, God, for bringing us together.
