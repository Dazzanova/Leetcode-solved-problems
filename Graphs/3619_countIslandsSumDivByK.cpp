class Solution {
public:
    int res = 0;

    void bfs(vector<vector<int>>& grid, vector<vector<int>>& vis,
        int r, int c, long long& sum, int k) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({r, c});
        vis[r][c] = 1;
        sum += grid[r][c];

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nr = row + dr[d];
                int nc = col + dc[d];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    !vis[nr][nc] && grid[nr][nc] > 0) {
                    vis[nr][nc] = 1;
                    sum += grid[nr][nc];
                    q.push({nr, nc});
                }
            }
        }
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] > 0) {
                    long long sum = 0;

                    bfs(grid, vis, i, j, sum, k);

                    if (sum % k == 0)
                        res++;
                }
            }
        }
        return res;
    }
};