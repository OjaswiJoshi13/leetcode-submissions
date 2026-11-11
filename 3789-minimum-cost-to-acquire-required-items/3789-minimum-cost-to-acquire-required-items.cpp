class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans1 = 0, ans2 = 0, ans3 = 0;

        ans1 = 1LL * cost1 * need1 + 1LL * cost2 * need2;

        long long x = min(need1, need2);
        long long y = max(need1, need2);

        ans2 = 1LL * x * costBoth + 1LL * (need1 - x) * cost1 + 1LL * (need2 - x) * cost2;

        ans3 = 1LL * y * costBoth;

        return min({ans1, ans2, ans3});
    }
};