class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,int>> q;

        int level=0;
        vector<vector<pair<int,int>>> adj(n);

        for(auto i:flights){
          adj[i[0]].push_back({i[1],i[2]});
        }

        vector<int> price(n,INT_MAX);
        price[src]=0;
        q.push({src,0});

        while(!q.empty() & level<=k){
            int size=q.size();
            while(size--){
                int x=q.front().first;
                int cost=q.front().second;
                q.pop();

                for(auto [key,value]:adj[x]){
                    if(cost+value<=price[key]){
                        price[key]=cost+value;
                        q.push({key,price[key]});
                    }
                }
            }
          level++;
        }


        return price[dst]==INT_MAX?-1:price[dst];
        
    }
};
