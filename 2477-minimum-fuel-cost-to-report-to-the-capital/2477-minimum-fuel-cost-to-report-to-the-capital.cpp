class Solution {
public:
    vector<vector<int>>adj;
    long long fuel;
    long long dfs(int node,int parent,int &seats){
        long long nodes=1;
        for (auto adjnode:adj[node]){
            if (adjnode!=parent){
                nodes+=dfs(adjnode,node,seats);
            }
        }
        if (node==0) return 0;
        fuel+=((nodes+seats-1)/seats);
        return nodes;

    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int m=roads.size();
        fuel=0ll;
        adj.resize(m+1);
        for (auto ed:roads){
            int u=ed[0];
            int v=ed[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0,-1,seats);

        return fuel;
    }
};