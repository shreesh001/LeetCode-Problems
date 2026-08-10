class Solution {
public:
    vector<int>depth,cost;
    vector<vector<pair<int,int>>>adj;
    vector<bool>vis;
    int cost_root=0;
    void dfs(int node,int d,int c){
        vis[node]=true;
        depth[node]=d;
        cost[node]=c;
        for (auto it:adj[node]){
            int adjnode=it.first;
            int cst=it.second;
            if (!vis[adjnode]){
                cost_root+=cst;
                dfs(adjnode,d+1,c+cst);
            }
        }
        return;
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for (auto ed:edges){
            int u=ed[0];
            int v=ed[1];
            adj[u].push_back({v,0});
            adj[v].push_back({u,1});
        }

        vis.resize(n,false);
        // depth is basically from the root node
        depth.resize(n,0);
        // cost is also basically from the root node
        cost.resize(n,0);

        dfs(0,0,0);
        vector<int>res(n,0);
        res[0]=cost_root;
        for (int i=1;i<n;i++){
            res[i]=res[0]+depth[i]-(2*cost[i]);
        }
        return res;
    }
};