class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        int count = 0;

        vector<int> dr = {1, 0, -1, 0};
        vector<int> dc = {0, 1, 0, -1};

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                // Start BFS only from an unvisited battleship cell
                if (board[r][c] == 'X' && vis[r][c] == 0) {

                    count++;

                    queue<pair<int, int>> q;
                    q.push({r, c});
                    vis[r][c] = 1;

                    while (!q.empty()) {
                        int cr = q.front().first;
                        int cc = q.front().second;
                        q.pop();

                        for (int i = 0; i < 4; i++) {
                            int nr = cr + dr[i];
                            int nc = cc + dc[i];

                            if (nr >= 0 && nc >= 0 &&
                                nr < m && nc < n &&
                                board[nr][nc] == 'X' &&
                                vis[nr][nc] == 0) {

                                vis[nr][nc] = 1;
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
};