class Solution {
public:
    bool checkString(string s) {
        int idx=s.size();
        for(int i=0;i<s.size();i++){
            if(s[i]=='b'){
                idx=i;
                break;
            }
        }

        for(int i=idx;i<s.size();i++){
            if(s[i]=='a'){
                return false;
            }
        }

        return true;
    }
};