class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m);
        string s1(n-1,'#');
        string s2 = "." + s1;
        string s3(n,'.');

        for(int i = 0; i<m;i++){
            if(i!=m-1){
                grid[i]=s2;
            }
            else{
                grid[i]=s3;
            }
        }

        return grid;
    }
};