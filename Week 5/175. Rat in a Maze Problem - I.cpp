#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int i, int j, vector<vector<int>> &a, int n, string s, vector<string> &res, vector<vector<int>> &vis) {
        if(i==n-1 && j==n-1) {
            res.push_back(s);
            return;
        }
        vis[i][j] = 1;
        if(j+1<n && !vis[i][j+1] && a[i][j+1]) {
            solve(i, j+1, a, n, s+'R', res, vis);
        }
        if(i+1<n && !vis[i+1][j] && a[i+1][j]) {
            solve(i+1, j, a, n, s+'D', res, vis);
        }
        if(i-1>=0 && !vis[i-1][j] && a[i-1][j]) {
            solve(i-1, j, a, n, s+'U', res, vis);
        }
        if(j-1>=0 && !vis[i][j-1] && a[i][j-1]) {
            solve(i, j-1, a, n, s+'L', res, vis);
        }
        vis[i][j] = 0;
    }

    vector<string> findPath(vector<vector<int>> &m) {
        int n = m.size();
        vector<string> res;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if(m[0][0] == 1) solve(0, 0, m, n, "", res, vis);
        return res;
    }
};
