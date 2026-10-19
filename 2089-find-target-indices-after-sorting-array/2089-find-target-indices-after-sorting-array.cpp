class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int c1=0,c2=0;
        for(int x : nums){
            if(x<target) c1++;
            else if(x==target) c2++;
        }

        vector<int> ans;
        for(int i=c1;i<c1+c2;i++){
            ans.push_back(i);
        }

        return ans;
    }
};