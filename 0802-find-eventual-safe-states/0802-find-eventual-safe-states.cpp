
class Solution {
public:

    bool dfs(int node, vector<int>& vis, vector<int>& path,
             vector<int>& safe, vector<vector<int>>& graph) {

        vis[node] = 1;
        path[node] = 1;

        for (auto edge : graph[node]) {
            if (!vis[edge]) {
                if (dfs(edge, vis, path, safe, graph)) {
                    path[node] = 0;
                    return true;
                }
            }

            else if (path[edge]) {
                path[node] = 0;
                return true;
            }

            else if (!safe[edge]) {
                path[node] = 0;
                return true;
            }
        }

        path[node] = 0;
        safe[node] = 1;

        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> vis(n, 0);
        vector<int> path(n, 0);
        vector<int> safe(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, vis, path, safe, graph);
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (safe[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
