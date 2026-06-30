class Solution {
public:
    vector<vector<pair<int,int>>>adj;
    vector<int>vis;

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        // reverse the edges to make sure that it will start form 0
        adj.resize(n);
        vis.resize(n,0);

        for (auto ed:edges){
            int u=ed[0];
            int v=ed[1];
            int wt=ed[2];
            adj[v].push_back({u,wt});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});

        int maxi_wt=0;
        while(!pq.empty()){
            auto [wt,node]=pq.top();
            pq.pop();
            if (vis[node]==1) continue;
            vis[node]=1;
            maxi_wt=max(maxi_wt,wt);

            for (auto it:adj[node]){
                int adjnode=it.first;
                int wt=it.second;
                if (!vis[adjnode]){
                    pq.push({wt,adjnode});
                }
            }
        }
        for (int i=0;i<n;i++){
            if (!vis[i]) return -1;
        }
        return maxi_wt;
    }
};