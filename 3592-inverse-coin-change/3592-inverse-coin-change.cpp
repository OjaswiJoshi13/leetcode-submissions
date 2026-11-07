class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();

        vector<long long> dp(n + 1, 0);
        vector<int> coins;

        dp[0] = 1;

        for(int i = 1; i <= n; i++) {

            if(dp[i] == numWays[i - 1]) {
                continue;
            }

            if(dp[i] + 1 != numWays[i - 1]) {
                return {};
            }

            coins.push_back(i);

            for(int j = i; j <= n; j++) {
                dp[j] += dp[j - i];
            }
        }

        return coins;
    }
};