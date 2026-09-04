class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int mx = INT_MIN;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);

            int mn = *min_element(nums.begin() + i, nums.end());

            if (mx - mn <= k)
                return i;
        }

        return -1;
    }
};