class Solution {
    // DSU (Disjoint Set Union) aur size vectors define kar rahe hain
    std::vector<int> dsu;
    std::vector<int> size;
public:
    // Find function banate hain jo path compression ke sath root find karta hai
    int find(int v) {
        if (dsu[v] == v) {
            return v; // Agar root mil gaya to wahi return karenge
        }
        return dsu[v] = find(dsu[v]); // Recursively root find karenge aur path compress karenge
    }

    // Union function banate hain jo size ke hisaab se merge karta hai
    void uni(int v1, int v2) {
        if (size[v1] < size[v2]) {
            std::swap(v1, v2); // Bade size wale component ko parent banayenge
        }
        size[v1] += size[v2]; // Size update karenge
        dsu[v2] = v1; // Component ko merge karenge
    }

    // Redundant edge find karne ke liye function banate hain
    vector<int> findRedundantConnection(const vector<vector<int>>& edges) {
        int n = edges.size();
        
        // DSU vector ko initialize karenge with indexes
        dsu = std::vector<int>(n);
        size = std::vector<int>(n, 1); // Har node ka initial size 1 rakhenge
        std::iota(dsu.begin(), dsu.end(), 0); // DSU ko initialize karenge 0 se n-1 tak
        
        // Har edge ke liye loop chalate hain
        for (std::uint32_t i = 0; i < n; ++i) {
            int v1 = find(edges[i][0] - 1); // First node ka root find karenge
            int v2 = find(edges[i][1] - 1); // Second node ka root find karenge
            
            if (v1 == v2) {
                return edges[i]; // Agar dono nodes ka root same hai to ye edge redundant hai
            } else {
                uni(v1, v2); // Nahi to inhe merge karenge
            }
        }
        
        return {0, 0}; // Agar koi redundant edge nahi mili to ye return karenge
    }
};
