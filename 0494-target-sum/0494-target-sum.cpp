class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;

        for (int x : nums) sum += x;

        if (abs(target) > sum) return 0;
        if ((sum + target) % 2 != 0) return 0;

        int req = (sum + target) / 2;

        vector<vector<int>> dp(n + 1, vector<int>(req + 1, 0));

        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= req; j++) {
                dp[i][j] = dp[i - 1][j];

                if (nums[i - 1] <= j) {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[n][req];
    }
};