class Solution {
public:
    vector<vector<int>>adj;
    vector<int>vis;
    vector<int>cnt_of_edges;

    int cnt_node;

    void dfs(int node,int parent,vector<int>&component){
        component.push_back(node);
        vis[node]=1;
        cnt_node+=1;
        for (auto adjnode:adj[node]){
            if (adjnode!=parent){
                if (!vis[adjnode]){
                    dfs(adjnode,node,component);
                }
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        vis.resize(n,0);
        cnt_of_edges.resize(n,0);

        for (auto ed:edges){
            int u=ed[0];
            int v=ed[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            cnt_of_edges[u]++;
            cnt_of_edges[v]++;
        }

        cnt_node=0;
        int res=0;
        for (int i=0;i<n;i++){
            if (vis[i]==0){
                vector<int>component;
                dfs(i,-1,component);
                bool to_add=true;
                for (auto node:component){
                    if (cnt_of_edges[node]!=cnt_node-1) to_add=false;
                }
                if (to_add) res+=1;
                cnt_node=0;
            }
        }
        return res;

    }
};