class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        // Hash map banate hain jisme hum store karenge subarray ka ending index jiska sum given sum hai
        unordered_map<int, int> map;

        // sum aur max_len ko 0 se initialize karte hain
        int sum = 0, max_len = 0;

        // Array ke through iterate karte hain
        for (int i = 0; i < n; i++) {
            // Current element ko sum me add karte hain
            sum += arr[i];

            // Agar sum 0 hai, toh max_len update karte hain
            if (sum == 0)
                max_len = i + 1;

            // Agar sum pehle se map me exist karta hai toh matlab
            // kuch subarray hai jo index i pe end ho raha hai
            // aur uska sum 0 hai
            if (map.find(sum) != map.end()) {
                // Agar zarurat ho toh max_len update karte hain
                max_len = max(max_len, i - map[sum]);
            } else {
                // Nahi toh is sum ko map me daalte hain
                map[sum] = i;
            }
        }

        // Return karte hain largest subarray ka length jiska sum 0 hai
        return max_len;
    }
};
