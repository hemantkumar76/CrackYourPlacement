class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // max profit store karne ke liye use karenge
        int max_profit = 0;
        // max profit store karne ke liye use karenge
        int cheap_hoga = prices[0];

        // abhi jo chal rha hai usse store karenge

        int current = 0;

        // iteration chalu karte hai
        for (int i = 0; i < prices.size(); i++) {
            // abhi kya hai ?
            current = prices[i];
            // agar currrent wala cheak se kam hai to cheap ko update kar denge
            if (cheap_hoga > current) {
                current = cheap_hoga;
            }
            if ((current - cheap_hoga) > max_profit) {
                max_profit = current - cheap_hoga;
            }
        }

        return max_profit;
    }
};
