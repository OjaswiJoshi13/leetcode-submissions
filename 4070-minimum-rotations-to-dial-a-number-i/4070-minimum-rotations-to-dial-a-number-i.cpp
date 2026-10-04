class Solution {
public:
    int minRotations(string s) {
        int ans=min(s[0] - '0', 10 - s[0]+ '0');

        for(int i=1;i<s.size();i++){
            ans+=min(abs(s[i] - '0' - s[i-1] + '0') , 10 - abs((s[i] - '0' - s[i-1] + '0')) );
        }

        return ans;
    }
};