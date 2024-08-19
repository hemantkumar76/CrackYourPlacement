#include <queue>
#include <vector>
#include <string>

class Solution {
public:
    string reorganizeString(string s) {
        // Ek array banate hain characters ki frequency store karne ke liye
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Ek max heap banate hain characters ko unki frequency ke basis pe store karne ke liye
        priority_queue<pair<int, char>> max_heap;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > (s.size() + 1) / 2) {
                return "";
            }
            if (freq[i] > 0) {
                max_heap.push({freq[i], i + 'a'});
            }
        }

        // Ek string banate hain answer store karne ke liye
        string result = "";

        // Jab tak heap me 2 ya 2 se zyada elements hain
        while (max_heap.size() >= 2) {
            // Heap ke top 2 elements ko nikalte hain
            auto [count1, char1] = max_heap.top(); max_heap.pop();
            auto [count2, char2] = max_heap.top(); max_heap.pop();

            // Unhe result me add karte hain
            result += char1;
            result += char2;

            // Agar unki frequency abhi bhi 0 se zyada hai toh unhe wapas heap me daalte hain
            if (--count1 > 0) {
                max_heap.push({count1, char1});
            }
            if (--count2 > 0) {
                max_heap.push({count2, char2});
            }
        }

        // Agar heap me abhi bhi koi element hai toh use result me add karte hain
        if (!max_heap.empty()) {
            result += max_heap.top().second;
        }

        // Result return karte hain
        return result;
    }
};
