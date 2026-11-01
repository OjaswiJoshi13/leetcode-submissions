class Solution:
    def minMergedInteger(self, nums: list[int]) -> int:
        ans = inf
        for i in range(0,len(nums)-1,2):
            x= str(nums[i]) + str(nums[i+1])
            ans=min(ans, int(x))

        return ans