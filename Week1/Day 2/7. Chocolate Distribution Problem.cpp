class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        // Sabse pehle, hum packets ko sort karte hain
        sort(a.begin(), a.end());

        // Fir, hum minimum difference ko maximum integer value se initialise karte hain
        long long min_diff = INT_MAX;

        // Ab, har packet ke liye, hum check karte hain ki kya yeh packet minimum difference ko kam kar sakta hai
        for (long long i = 0; i <= n - m; i++) {
            // Agar yeh packet minimum difference ko kam kar sakta hai, toh hum minimum difference ko update karte hain
            long long diff = a[i + m - 1] - a[i];
            if (diff < min_diff)
                min_diff = diff;
        }

        // Ant mein, hum minimum difference return karte hain
        return min_diff;
    }   
};
