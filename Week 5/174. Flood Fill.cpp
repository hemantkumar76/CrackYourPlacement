class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {

        queue<pair<int, int>> q;
        q.push({sr, sc});

        int m = image.size();
        int n = image[0].size();
        // adjency list banate hia
        int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int bsdk = image[sr][sc];

        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            // agarpainted rha then skip karega 
            if (image[i][j] == color) {
                continue;
            }

            image[i][j] = color;

            for (int f = 0; f < 4; f++) {
                int next = i + direction[f][0];
                int next2 = j + direction[f][1];

                if (next >= 0 && next2 >= 0 && next < m && next2 < n && image[next][next2] == bsdk) 
                {
                    q.push({next, next2});
                }
            }
        }
        return image;
    }
};
