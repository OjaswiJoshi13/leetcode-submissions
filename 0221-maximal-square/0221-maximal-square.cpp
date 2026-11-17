class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        int max_side = 0;

        for (int i = (int) matrix.size() - 1; i >= 0; --i) {
            for (int j = (int) matrix[0].size() - 1; j >= 0; --j) {
                if (matrix[i][j] == '0') continue;
                dp[i][j] = 1 + min(dp[i + 1][j], min(dp[i][j + 1], dp[i + 1][j + 1]));
                max_side = max(max_side, dp[i][j]);
            }
        }

        return max_side * max_side;
    }
};