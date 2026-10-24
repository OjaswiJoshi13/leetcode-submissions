class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int left=0;
        long long ans=0;

        for(int right=0;right<nums.size();right++){
            if(nums[right]<=maxK && nums[right]>=minK){
                ans+=right-left+1;
            }
            else{
                left=right+1;
            }
        }
        return ans;
    }
};