class Solution {
public:
    vector<vector<pair<int,int>>>adj;
    vector<int>vis;
    int dfs(int node){
        vis[node]=1;
        int maxi=1e4;
        for (auto it:adj[node]){
            int adjnode=it.first;
            int dist=it.second;
            maxi=min(maxi,dist);
            if (!vis[adjnode]){ 
                maxi=min(maxi,dfs(adjnode));
            }
        }
        return maxi;
    }
    int minScore(int n, vector<vector<int>>& roads) {

        adj.resize(n);
        vis.resize(n,0);
        for (auto ed:roads){
            int u=ed[0]-1;
            int v=ed[1]-1;
            int wt=ed[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        int ans=dfs(0);
        return ans;
    }
};