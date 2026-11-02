
class Solution {
public:

    bool dfs(int node, vector<int>& vis, vector<vector<int>>& graph) {

        vis[node] = 1;

        for (auto edge : graph[node]) {

            if (vis[edge] == 0) {
                if (dfs(edge, vis, graph))
                    return true;
            }

            else if (vis[edge] == 1) {
                return true;
            }
        }

        vis[node] = 2;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                dfs(i, vis, graph);
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (vis[i] == 2) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
