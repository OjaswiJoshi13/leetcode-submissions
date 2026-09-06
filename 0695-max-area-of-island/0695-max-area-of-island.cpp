class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        int maxArea = 0;

        vector<int> dr = {1, 0, -1, 0};
        vector<int> dc = {0, 1, 0, -1};

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                // Found a new island
                if(grid[i][j] == 1 && vis[i][j] == 0) {

                    int area = 0;

                    queue<pair<int,int>> q;

                    q.push({i, j});
                    vis[i][j] = 1;

                    while(!q.empty()) {

                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();

                        area++;

                        // Check 4 directions
                        for(int k = 0; k < 4; k++) {

                            int nr = r + dr[k];
                            int nc = c + dc[k];

                            if(nr >= 0 && nc >= 0 &&
                               nr < m && nc < n &&
                               grid[nr][nc] == 1 &&
                               vis[nr][nc] == 0) {

                                vis[nr][nc] = 1;
                                q.push({nr, nc});
                            }
                        }
                    }

                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};