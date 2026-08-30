class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();

        int mx=*max_element(nums.begin(),nums.end());
        int mn=*min_element(nums.begin(),nums.end());

        int mxInd=-1,mnInd=-1;

        for(int i=0;i<n;i++){
            if(nums[i]==mx) mxInd=i;
            if(nums[i]==mn) mnInd=i;
        }

        int left=max(mxInd,mnInd) + 1;
        int right=max(n-mxInd,n-mnInd);

        return min({left,right,mxInd+1+n-mnInd,mnInd+1+n-mxInd});
    }
};