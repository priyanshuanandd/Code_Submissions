class Solution {
public:
    vector<vector<int>> grid;
    map<int, int> colour_cnt;
    int n, m;
    vector<vector<int>> vis;
    int cnt;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    void flood_fill(int x, int y) {
        vis[x][y] = 1;
        grid[x][y] = cnt;
        colour_cnt[cnt]++;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 0 and xx < n and yy < m and yy >= 0 and
                grid[xx][yy] == 1 and vis[xx][yy] == 0) {
                flood_fill(xx, yy);
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid2) {
        grid = grid2;
        n = grid.size();
        m = grid[0].size();
        vis.assign(n, vector<int>(m, 0));
        cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 and grid[i][j] == 1) {
                    cnt++;
                    flood_fill(i, j);
                }
            }
        }

        for (auto i : grid) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << '\n';
        }
        int maxi = 0;
        for (auto i : colour_cnt) {
            cout << i.first << "->" << i.second << endl;
            maxi = max(maxi, i.second);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    set<int> s;
                    for (int k = 0; k < 4; k++) {
                        int xx = i + dx[k];
                        int yy = j + dy[k];
                        if (xx >= 0 and xx < n and yy < m and yy >= 0) {
                            if (grid[xx][yy] != 0) {
                                s.insert(grid[xx][yy]);
                            }
                        }
                    }
                    int curr = 0;
                    while (!s.empty()) {
                        curr += colour_cnt[*s.begin()];
                        s.erase(s.begin());
                    }
                    maxi = max(maxi, curr+1);
                }
            }
        }

        return maxi;
    }
};

/*
|CCC|CCC|CCC|CCC|
|   |   |   |CCC|
|CCC|CCC|CCC|   |
|   |   |   |   |

*/