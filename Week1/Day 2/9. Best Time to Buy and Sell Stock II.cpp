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

// however today this was the good day for me i got a new person in my life i hope now i have got that what i wanted 
