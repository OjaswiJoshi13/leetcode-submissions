class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();

        vector<vector<int>> vis(n,vector<int> (m,0));

        vector<int> dr={0,1,0,-1};
        vector<int> dc={1,0,-1,0};

        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(r==sr && c==sc){
                    int original=image[r][c];
                    image[r][c]=color;
                    vis[r][c]=1;
                    queue<pair<int,int>> q;
                    q.push({r,c});

                    while(!q.empty()){
                        auto [i,j] = q.front();
                        q.pop();

                        for(int k=0;k<4;k++){
                            int nr=i+dr[k];
                            int nc=j+dc[k];

                            if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] and image[nr][nc]==original){
                                vis[nr][nc]=1;
                                original=image[nr][nc];
                                q.push({nr,nc});
                                image[nr][nc]=color;
                            }
                        }
                    }
                }
            }
        }

        return image;
    }
};