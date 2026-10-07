class Solution {
public:
    unordered_set<string> st;

    void solve(string &s,int i,int l,int r,int rl,int rr,string curr){
        if(i==s.size()){
            if(rl==0 && rr==0 && l==r){
                st.insert(curr);
            }
            return;
        }

        if(s[i]=='(' && rl>0){
            solve(s,i+1,l,r,rl-1,rr,curr);
        }

        if(s[i]==')' && rr>0){
            solve(s,i+1,l,r,rl,rr-1,curr);
        }

        if(s[i]!='(' && s[i]!=')'){
            solve(s,i+1,l,r,rl,rr,curr+s[i]);
        }
        else if(s[i]=='('){
            solve(s,i+1,l+1,r,rl,rr,curr+s[i]);
        }
        else{
            if(l>r){
                solve(s,i+1,l,r+1,rl,rr,curr+s[i]);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int l=0,r=0;

        for(char c:s){
            if(c=='('){
                l++;
            }
            else if(c==')'){
                if(l>0) l--;
                else r++;
            }
        }

        solve(s,0,0,0,l,r,"");

        return vector<string>(st.begin(),st.end());
    }
};