class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    bool closed = true;
                    stack<pair<int, int>> st;
                    st.push({i, j});
                    grid[i][j] = 1;

                    while (!st.empty()) {
                        auto [r, c] = st.top();
                        st.pop();

                        if (r == 0 || c == 0 || r == n - 1 || c == m - 1)
                            closed = false;

                        for (int k = 0; k < 4; k++) {
                            int nr = r + dr[k];
                            int nc = c + dc[k];

                            if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                                grid[nr][nc] == 0) {
                                grid[nr][nc] = 1;
                                st.push({nr, nc});
                            }
                        }
                    }

                    if (closed)
                        count++;
                }
            }
        }

        return count;
    }
};