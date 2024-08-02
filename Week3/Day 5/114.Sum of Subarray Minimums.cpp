class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // Ek stack banate hain jisme hum array ke indices store karenge
        stack<int> s;
        
        // Array ki size ko n me store karte hain
        int n = arr.size();
        
        // Left aur right array banate hain jisme hum store karenge ki har element ke liye left aur right me pehla chota element kitna door hai
        vector<int> left(n), right(n);
        
        // Left array calculate karte hain
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        
        // Stack ko khali karte hain
        while (!s.empty()) {
            s.pop();
        }
        
        // Right array calculate karte hain
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        
        // Sum calculate karte hain
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += (long long)arr[i] * (i - left[i]) * (right[i] - i);
            sum %= 1000000007;
        }
        
        // Sum return karte hain
        return sum;
    }
};
