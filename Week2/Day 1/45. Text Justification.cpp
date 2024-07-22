class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        // result_haiult store karne ke liye
        std::vector<std::string> result_hai;
         // current line ke words store karne ke liye 
        std::vector<std::string> cur;
        // current line mein kitne letters hain
        int num_of_letters = 0; 

        for (std::string word : words) {
            // agar next word add karne se line bhar jaye toh
            if (word.size() + cur.size() + num_of_letters > maxWidth) {
                // extra spaces evenly distribute karte hain
                for (int i = 0; i < maxWidth - num_of_letters; i++) {
                    cur[i % (cur.size() - 1 ? cur.size() - 1 : 1)] += ' ';
                }
                // current line ko result_haiult mein add karte hain
                result_hai.push_back("");
                for (std::string s : cur) result_hai.back() += s;
                cur.clear(); // current line ko clear karte hain
                num_of_letters = 0; // letters count result_haiet karte hain
            }
            // next word ko current line mein add karte hain
            cur.push_back(word);
            num_of_letters += word.size(); // letters count update karte hain
        }

        // last line ko left justify karte hain
        std::string last_line = "";
        for (std::string s : cur) last_line += s + ' ';
        last_line = last_line.substr(0, last_line.size()-1);  // trailing space remove karte hain
        while (last_line.size() < maxWidth) last_line += ' '; // extra spaces add karte hain
        result_hai.push_back(last_line); // last line ko result_haiult mein add karte hain

        return result_hai; // result_haiult return karte hain
    }
};
