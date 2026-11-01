class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1);
        queue<int> q;

        for(int i = 0; i < n; i++) {

            if(color[i] != -1) continue;

            color[i] = 0;
            q.push(i);

            while(!q.empty()) {
                int parent = q.front();
                q.pop();

                for(auto node : graph[parent]) {

                    if(color[node] == -1) {
                        color[node] = 1 - color[parent];
                        q.push(node);
                    }
                    else {
                        if(color[node] == color[parent])
                            return false;
                    }
                }
            }
        }

        return true;
    }
};