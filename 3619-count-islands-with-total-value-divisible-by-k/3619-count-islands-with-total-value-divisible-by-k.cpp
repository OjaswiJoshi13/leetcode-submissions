class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] > 0 && !vis[i][j]) {
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i][j] = 1;

                    long long sum = 0;

                    while(!q.empty()) {
                        auto [r,c] = q.front();
                        q.pop();

                        sum += grid[r][c];

                        for(int d = 0; d < 4; d++) {
                            int nr = r + dr[d];
                            int nc = c + dc[d];

                            if(nr >= 0 && nr < n && nc >= 0 && nc < m &&
                               !vis[nr][nc] && grid[nr][nc] > 0) {
                                vis[nr][nc] = 1;
                                q.push({nr,nc});
                            }
                        }
                    }

                    if(sum % k == 0) count++;
                }
            }
        }

        return count;
    }
};