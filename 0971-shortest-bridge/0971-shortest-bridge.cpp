class Solution {
public:
    vector<vector<int>> grid;
    int n, m;
    int cnt = 2;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    queue<pair<int, int>> q;
    void f(int x, int y) {
        grid[x][y] = cnt;
        q.push({x, y});
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];     
            if(xx >= 0 and xx < n and yy < m and yy >= 0 and grid[xx][yy] == 1){
                f(xx, yy);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid2) {
        grid = grid2;
        n = grid.size();
        m = grid[0].size();
        cout << n << " " << m << endl;
        int fl = 0 ;
        for (int i = 0; fl==0 and i < n; i++) {
            for (int j = 0; fl==0 and j < m; j++) {
                if (grid[i][j] == 1) {
                    f(i, j);
                    fl = 1;
                }
            }
        }
        for(auto i : grid){
            for(auto j : i){
                cout << j << " ";
            }
            cout << endl;
        }
        // multi source bfs goes here boom !!!

        int mini = 1e9;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i  = 0; i < 4; i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (xx >= 0 and xx < n and yy >= 0 and yy < m) {
                    if (grid[xx][yy] == 0 or grid[xx][yy]>grid[x][y]+1) {
                        grid[xx][yy] = grid[x][y] + 1;
                        q.push({xx, yy});
                    } else if (grid[xx][yy] == 1) {
                        mini = min(mini, grid[x][y] - 2);
                    }
                }
            }
        }
        return mini;
    }
};

/*

[1,1,1,1,1],
[1,0,0,0,1],
[1,0,1,0,1],
[1,0,0,0,1],
[1,1,1,1,1]

*/