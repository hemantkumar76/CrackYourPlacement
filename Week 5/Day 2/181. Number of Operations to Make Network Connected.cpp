#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // Agar connections kam hain toh -1 return karo
        if(connections.size() < n-1) return -1;
        
        vector<int> parent(n);
        // Sabhi computers ko apne parent banado
        for(int i=0; i<n; i++) parent[i] = i;
        
        int extra = 0; // Extra connections count karo
        for(auto& conn : connections) {
            int p1 = find(parent, conn[0]);
            int p2 = find(parent, conn[1]);
            if(p1 != p2) { // Agar dono computers alag group me hain toh unko jodo
                parent[p1] = p2;
            } else { // Agar dono computers same group me hain toh yeh connection extra hai
                extra++;
            }
        }
        
        int groups = 0; // Total groups count karo
        for(int i=0; i<n; i++) {
            if(parent[i] == i) groups++;
        }
        
        // Agar extra connections kam hain toh -1 return karo
        return (extra < groups-1) ? -1 : groups-1;
    }
    
private:
    int find(vector<int>& parent, int i) {
        if(parent[i] != i) {
            parent[i] = find(parent, parent[i]);
        }
        return parent[i];
    }
};
