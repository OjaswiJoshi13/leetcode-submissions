class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();

        vector<vector<int>> ans(m, vector<int>(n, -1));

        vector<int> dr = {1, 0, -1, 0};
        vector<int> dc = {0, 1, 0, -1};

        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];

                if(nr>=0 && nc>=0 && nr<m && nc<n && ans[nr][nc]==-1){
                    ans[nr][nc]=ans[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }

        return ans;


    }
};