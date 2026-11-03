class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);

        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        for(int i = 0;i<numCourses;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i = 0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        int count=0;
        vector<int> topo;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            topo.push_back(node);
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        if(count==numCourses){
            return topo;
        }

        return {};
    }
};