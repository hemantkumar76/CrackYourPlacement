class Solution
{
	public:
	// Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // Pehle har node ka indegree calculate karenge.
	    vector<int> indegree(V, 0);
	    
	    // Har node ke liye, uske adjacent nodes ka indegree increment karenge.
	    for(int i = 0; i < V; i++) {
	        for(int it : adj[i]) {
	            indegree[it]++;
	        }
	    }
	    
	    // Queue banayenge jisme saare nodes honge jinka indegree 0 hai.
	    queue<int> q;
	    for(int i = 0; i < V; i++) {
	        if(indegree[i] == 0) q.push(i);
	    }
	    
	    // Topological sort ke result ko store karne ke liye vector banayenge.
	    vector<int> topo;
	    
	    // Jab tak queue khali na ho, tab tak process karenge.
	    while(!q.empty()) {
	        // Queue ke front se node nikalenge.
	        int node = q.front();
	        q.pop();
	        
	        // Topological sort mein current node ko add karenge.
	        topo.push_back(node);
	        
	        // Har adjacent node ka indegree decrement karenge.
	        for(int it : adj[node]) {
	            indegree[it]--;
	            
	            // Agar kisi adjacent node ka indegree 0 ho jaye, to usko queue mein daalenge.
	            if(indegree[it] == 0) q.push(it);
	        }
	    }
	    return topo;
	}
};
