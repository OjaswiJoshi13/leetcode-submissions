
class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        int x = 0, y = 0;
        vis[x][y] = 1;

        while (true) {
            int nx = x, ny = y;
            char c = grid[x][y];

            if (c == 'R') ny++;
            else if (c == 'L') ny--;
            else if (c == 'U') nx--;
            else if (c == 'D') nx++;

            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                break;

            if (vis[nx][ny])
                break;

            x = nx;
            y = ny;
            vis[x][y] = 1;
        }

        return {x, y};
    }
};
