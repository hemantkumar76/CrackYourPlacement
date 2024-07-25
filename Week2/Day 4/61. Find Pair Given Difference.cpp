class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        // Pehle array ko sort karte hain
        sort(arr.begin(), arr.end());

        // Do pointers initialize karte hain, ek start pe aur ek end pe
        int i = 0, j = n - 1;

        // Jab tak ki pointers ek dusre se milte nahi, loop chalate rahe
        while (i < j) {
            // Agar difference x ke barabar hai, toh 1 return karte hain
            if (arr[j] - arr[i] == x) {
                return 1;
            }
            // Agar difference x se kam hai, toh start pointer ko aage badhate hain
            else if (arr[j] - arr[i] < x) {
                i++;
            }
            // Agar difference x se zyada hai, toh end pointer ko peeche le jaate hain
            else {
                j--;
            }
        }

        // Agar koi pair nahi mila, toh -1 return karte hain
        return -1;
    }
};
