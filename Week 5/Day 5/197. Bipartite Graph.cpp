bool isBipartite(int V, vector<int> adj[]) {
    vector<int> color(V, -1); // Har node ka color -1 se initialize kar rahe hain
    queue<int> q; // BFS ke liye queue use karenge

    for(int i = 0; i < V; i++) {
        if(color[i] == -1) { // Agar node ka color ab tak assign nahi hua
            q.push(i); // Us node ko queue mein daalenge
            color[i] = 0; // Pehla color assign kar rahe hain

            while(!q.empty()) { // Jab tak queue khali nahi hoti
                int Node = q.front(); // Queue se front node le rahe hain
                q.pop(); // Queue se node ko hata rahe hain

                for(int j = 0; j < adj[Node].size(); j++) {
                    if(color[adj[Node][j]] == -1) { // Agar adjacent node ka color ab tak assign nahi hua
                        color[adj[Node][j]] = (color[Node] + 1) % 2; // Alternate color assign kar rahe hain
                        q.push(adj[Node][j]); // Us adjacent node ko queue mein daalenge
                    } else {
                        if(color[Node] == color[adj[Node][j]]) // Agar same color mil gaya adjacent node ka
                            return 0; // Bipartite nahi hai
                    }
                }
            }
        }
    }
    return 1; // Bipartite hai
}
