class Solution {
public:
    // graph banane ke liye ek map banate hai
    unordered_map<string, unordered_map<string, double>> graph_hai;

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        // loop chalaya hai saare given equation ke liye
        for (int i = 0; i < equations.size(); i++) {
            const string& A = equations[i][0];
            const string& B = equations[i][1];
            const double k = values[i];
            // addd karte hai eq graph me
            graph_hai[A][B] = k;
            graph_hai[B][A] = 1.0 / k;
        }

        vector<double> ans_hoga;
        // Sabhi queries ke liye loop chalaya hai
        for (const auto& saare_pairs : queries) {
            const string& X = saare_pairs[0];
            const string& Y = saare_pairs[1];
            // Agar X ya Y graph mein nahi hai toh -1.0 add kiya hai
            if (!graph_hai.count(X) || !graph_hai.count(Y)) {
                ans_hoga.push_back(-1.0);
                continue;
            }
            // visited nodes track karne ke liye  map banate hai
            unordered_map<string, int> visited_hai;
            // dfs call karte hai 
            ans_hoga.push_back(dfs(X, Y, visited_hai));
        }
        return ans_hoga;
    }
    // dfs wala dunc
    double dfs(const string& x, const string& y,
               unordered_map<string, int>& visited_hai) {
        // Agar x aur y same hai toh 1.0 return kiya hai
        if (x == y)
        {

            return 1.0;
        }
        // x ko visited mark kiya hai
        visited_hai[x] = 1;
        // x ke neighbours ke liye loop chalaya hai
        for (const auto& saare_pairs : graph_hai[x]) {
            const string& next_hoga = saare_pairs.first;
            // Agar neighbour already visited hai toh skip kiya hai
            if (visited_hai.count(next_hoga))
            {

                continue;
            }
            // DFS se neighbour ka result calculate kiya hai
            double lol = dfs(next_hoga, y, visited_hai);
            // Agar result positive hai toh usse return kiya hai
            if (lol > 0)
            {

                return lol * graph_hai[x][next_hoga];
            }
        }
        return -1.0;
    }
};
