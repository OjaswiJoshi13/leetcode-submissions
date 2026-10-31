class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i : nums) sum+=i;

        if(sum%2!=0) return false;

        int val = sum/2;

        vector<bool> dp(val+1,false);
        dp[0]=true;

        for(int num : nums){
            for(int i=val ; i>=num ; i--){
                dp[i]=dp[i] || dp[i-num];
                if(dp[val]) return true;
            }
        }

        return dp[val];
    }
};