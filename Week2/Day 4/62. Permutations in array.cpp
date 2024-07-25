class Solution {

  public:
    bool isPossible(long long a[], long long b[], int n, long long k) {
        // Pehle dono arrays ko sort karte hain, ek ascending order mein aur ek descending order mein
        sort(a, a + n);
        sort(b, b + n, greater<int>());

        // Fir har element ke liye check karte hain ki kya sum of corresponding elements K se bada ya barabar hai
        for (int i = 0; i < n; i++) {
            if (a[i] + b[i] < k) {
                // Agar kisi bhi element ke liye yeh condition false hai, toh false return karte hain
                return false;
            }
        }

        // Agar sabhi elements ke liye condition true hai, toh true return karte hain
        return true;
    }
};

