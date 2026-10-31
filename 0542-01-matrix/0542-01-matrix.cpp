class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        vector<vector<int>> dis(m, vector<int>(n, -1));

        vector<int> dr = {1, 0, -1, 0};
        vector<int> dc = {0, 1, 0, -1};

        queue<pair<int,int>> q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    dis[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(int k=0; k<4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr>=0 && nc>=0 && nr<m && nc<n && dis[nr][nc] == -1){

                    dis[nr][nc] = dis[r][c] + 1;
                    q.push({nr,nc});

                }
            }
        }

        return dis;
    }
};