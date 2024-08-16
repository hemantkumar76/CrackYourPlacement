
class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        // Graph banane ke liye adjacency list banayenge
        vector<int> adj[K]; 
        
        // Har pair of adjacent words ko compare karenge
        for (int i = 0; i < N-1; i++) {
            string word1 = dict[i];
            string word2 = dict[i+1];
            for (int j = 0; j < min(word1.size(), word2.size()); j++) {
                if (word1[j] != word2[j]) {
                    // Agar characters different hain, toh unke bich edge add karenge
                    adj[word1[j] - 'a'].push_back(word2[j] - 'a');
                    break; // First mismatching character par hi edge add karenge
                }
            }
        }
        
        // Topological sort ke liye in-degree array banayenge
        vector<int> inDegree(K, 0);
        for (int i = 0; i < K; i++) {
            for (auto it : adj[i]) {
                inDegree[it]++;
            }
        }
        
        // Topological sort ke liye queue use karenge
        queue<int> q;
        for (int i = 0; i < K; i++) {
            if (inDegree[i] == 0) {
                q.push(i); // Jinki in-degree 0 hai, unhe queue mein dalenge
            }
        }
        
        string order = ""; // Resultant string store karne ke liye
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order += (char)(node + 'a'); // Node ko result mein add karenge
            
            for (auto it : adj[node]) {
                inDegree[it]--;
                if (inDegree[it] == 0) {
                    q.push(it); // In-degree 0 hone par queue mein add karenge
                }
            }
        }
        
        return order; // Final order return karenge
    }
};
