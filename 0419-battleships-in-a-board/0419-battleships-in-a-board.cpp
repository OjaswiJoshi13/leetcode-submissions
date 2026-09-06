class Solution {
public:
    void dfs(vector<vector<char>>& board, int r,int c,int m, int n, vector<vector<int>>& vis){
        vector<int> dr={1,0,-1,0};
        vector<int> dc={0,1,0,-1};

        vis[r][c]=1;

        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];

            if(nr>=0 && nc>=0 && nr<m && nc<n && board[nr][nc]=='X' && !vis[nr][nc]){
                vis[nr][nc]=1;
                dfs(board,nr,nc,m,n,vis);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        vector<vector<int>> vis(m,vector<int> (n));

        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X' && !vis[i][j]){
                    count++;
                    dfs(board,i,j,m,n,vis);
                }
            }
        }

        return count;
    }
};