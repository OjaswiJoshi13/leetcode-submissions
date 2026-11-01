class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m, vector<int> (n,0));

        vector<int> dr = {1,0,-1,0};
        vector<int> dc = {0,1,0,-1};

        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || j==0 || i==m-1 || j==n-1) && !vis[i][j] && grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(int i = 0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0 && nc>=0 && nr<m && nc<n && !vis[nr][nc] && grid[nr][nc]==1){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }

        int count=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    count++;
                }
            }
        }

        return count;
    }
};