vector<int> bfsOfGraph(int V, vector<int> adj[]) {
       
       queue<int>q;
       int src = 0;
       q.push(src);

       unordered_map<int,bool>visited;
       visited[src]=true;

       vector<int>ans;
       while(!q.empty())
       {
           int frontNode  = q.front();
           q.pop();
           ans.push_back(frontNode);  
           for(auto n : adj[frontNode])
           {
           if(!visited[n])
           {
               q.push(n);
             visited[n]=true; 
           }
           }
       }
       return ans;
    }
