class Solution {
public:
    vector<int>suspicious;
    vector<vector<int>>adj;
    vector<bool>vis;
    bool marker;

    void dfs(int node){
        suspicious[node]=1;
        vis[node]=true;
        for (auto adjnode:adj[node]){
            if (!vis[adjnode]){
                dfs(adjnode);
            }
        }
    }

    void solvedfs(int node){
        if (suspicious[node]==1) marker=true;
        suspicious[node]=0;
        vis[node]=true;
        for (auto adjnode:adj[node]){
            if (!vis[adjnode]){
                solvedfs(adjnode);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        adj.resize(n);
        suspicious.assign(n,0);
        vis.assign(n,false);

        for (auto ed:invocations){
            int u=ed[0];
            int v=ed[1];
            adj[u].push_back(v);
        }

        dfs(k);
        vis.assign(n,false);
        marker=false;

        for (int i=0;i<n;i++){
            if (suspicious[i]==0 && vis[i]==false){
                solvedfs(i);
            }
        }

        vector<int>res;
        
        for (int i=0;i<n;i++){
            if (marker==true) res.push_back(i);
            else if (suspicious[i]==0) res.push_back(i);
        }

        return res;
    }
};