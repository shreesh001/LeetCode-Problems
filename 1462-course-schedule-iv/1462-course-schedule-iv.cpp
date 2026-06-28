class Solution {
public:
    void dfs(int node,int srtnode,vector<vector<int>>&adj,vector<vector<bool>>&isReachable){
        isReachable[srtnode][node]=true;
        for (auto adjnode:adj[node]){
            if (!isReachable[srtnode][adjnode]) {
                dfs(adjnode,srtnode,adj,isReachable);
            }
        }
        return;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>>adj(numCourses);
        for (auto ed:prerequisites){
            int u=ed[0];
            int v=ed[1];
            adj[u].push_back(v);
        }
        vector<vector<bool>>isReachable(numCourses,vector<bool>(numCourses,false));

        for (int i=0;i<numCourses;i++){
            dfs(i,i,adj,isReachable);
        }

        vector<bool>ans;
        for (auto q:queries){
            int u=q[0];
            int v=q[1];
            ans.push_back(isReachable[u][v]);
        }
        return ans;

    }
};