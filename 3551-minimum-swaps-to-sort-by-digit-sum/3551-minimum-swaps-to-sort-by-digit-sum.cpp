        
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> digitsum;

        for (int i = 0; i < n; i++) {
            int x = nums[i], sum = 0;

            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }

            digitsum.push_back({sum, nums[i]});
        }

        sort(digitsum.begin(), digitsum.end());

        unordered_map<int, int> pos;

        for (int i = 0; i < n; i++) {
            pos[digitsum[i].second] = i;
        }

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || pos[nums[i]] == i)
                continue;

            int j = i;
            int cycleSize = 0;

            while (!visited[j]) {
                visited[j] = true;
                j = pos[nums[j]];
                cycleSize++;
            }

            swaps += cycleSize - 1;
        }

        return swaps;
    }
};