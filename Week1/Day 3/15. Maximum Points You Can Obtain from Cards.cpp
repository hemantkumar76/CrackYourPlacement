class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // Total points ka sum calculate karte hain
        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        // Window size calculate karte hain
        int n = cardPoints.size();
        int wind_ka_size = n - k;
        // Pehle window ka sum calculate karte hain
        int wind_ka_sum = accumulate(cardPoints.begin(), cardPoints.begin() + wind_ka_size, 0);
        // Minimum window sum dhundte hain
        int minwind_ka_sum = wind_ka_sum;
        for (int i = wind_ka_size; i < n; i++) {
            // Window ko slide karte hain
            wind_ka_sum += cardPoints[i] - cardPoints[i - wind_ka_size];
            // Minimum window sum update karte hain
            minwind_ka_sum = min(minwind_ka_sum, wind_ka_sum);
        }
        // Maximum score return karte hain
        return total - minwind_ka_sum;
    }
};
