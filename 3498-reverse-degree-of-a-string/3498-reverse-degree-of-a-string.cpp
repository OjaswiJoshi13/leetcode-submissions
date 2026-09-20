class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        string rev = "zyxwvutsrqponmlkjihgfedcba";
        for(int i=0;i<s.size();i++){
            int val;
            for(int j=0;j<26;j++){
                if(s[i]==rev[j]){
                    val=j+1;
                    break;
                }
            }

            ans+= val*(i+1);
        }
        return ans;
    }
};