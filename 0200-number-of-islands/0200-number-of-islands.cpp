class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;

        vector<vector<int>> vis(n,vector<int> (m,0));
        vector<int> dr={0,1,0,-1};
        vector<int> dc={1,0,-1,0};

        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(grid[r][c]=='1' && !vis[r][c]){
                    count++;
                    vis[r][c]=1;

                    stack<pair<int,int>> st;
                    st.push({r,c});

                    while(!st.empty()){
                        auto [i,j] = st.top();
                        st.pop();

                        for(int k=0;k<4;k++){
                            int nr=i+dr[k];
                            int nc=j+dc[k];

                            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1' && !vis[nr][nc]){
                                vis[nr][nc]=1;
                                st.push({nr,nc});
                            }
                        }
                    }
                }
            }
        }

        return count;

    }
};