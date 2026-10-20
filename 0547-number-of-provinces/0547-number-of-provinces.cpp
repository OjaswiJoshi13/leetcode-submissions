class Solution {

private:

    void dfs(int node, vector<int> &vis, vector<vector<int>>& adj){
        vis[node]=1;

        for(auto v : adj[node]){
            if(!vis[v]){
                dfs(v, vis, adj);
            }            
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();

        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n,0);
        int ans=0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i, vis, adj);
            }
        }        

        return ans;

    }
};