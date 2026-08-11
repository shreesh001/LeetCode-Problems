class Solution {
public:
    using ll=long long;
    vector<ll>depth;
    vector<vector<int>>adj;
    ll dfs(int node,int parent,int d){
        depth[node]=d;
        int h=1;
        int child_height=0;
        for (auto adjnode:adj[node]){
            if (adjnode!=parent){
                int height=dfs(adjnode,node,d+1);
                child_height=max(child_height,height);
            }
        }
        return h+child_height;
    }
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n=parent.size();
        depth.resize(n,0);
        adj.resize(n);
        for (int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }

        ll h=dfs(0,-1,1);

        ll sum=0;
        for (int i=0;i<n;i++){
            sum+=(1ll*nums[i])*(h-depth[i]+1ll);
        }
        return sum;
    }
};