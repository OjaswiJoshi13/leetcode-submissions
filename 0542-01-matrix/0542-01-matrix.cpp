class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        vector<vector<int>> dis(m, vector<int>(n, 0));

        vector<int> dr = {1, 0, -1, 0};
        vector<int> dc = {0, 1, 0, -1};

        vector<int> vis(m*n, 0);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                if(mat[i][j] == 1){

                    queue<pair<int,int>> q;

                    int id = i*n + j + 1;

                    q.push({i,j});
                    vis[i*n+j] = id;

                    int ans = 0;
                    bool found = false;

                    while(!q.empty()){

                        int sz = q.size();
                        ans++;

                        while(sz--){

                            auto [r,c] = q.front();
                            q.pop();

                            for(int k=0; k<4; k++){

                                int nr = r + dr[k];
                                int nc = c + dc[k];

                                if(nr>=0 && nc>=0 && nr<m && nc<n &&
                                   vis[nr*n+nc] != id){

                                    if(mat[nr][nc] == 0){
                                        found = true;
                                        break;
                                    }

                                    vis[nr*n+nc] = id;
                                    q.push({nr,nc});
                                }
                            }

                            if(found) break;
                        }

                        if(found) break;
                    }

                    dis[i][j] = ans;
                }
            }
        }

        return dis;
    }
};