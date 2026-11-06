class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int stair1 = 0, stair2 = 0;

        for(int i = n-1 ;i >= 0;i--){
            int x = cost[i] + min(stair1,stair2);
            stair2=stair1;
            stair1=x;
        }

        return min(stair1,stair2);
    }
};