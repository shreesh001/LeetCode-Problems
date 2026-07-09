class Solution {
public:
    vector<int>parent;
    vector<int>size;
    int findparent(int node){
        if (node==parent[node]) return node;
        return parent[node]=findparent(parent[node]);
    }
    void UnionbySize(int u,int v){
        int parent_u=findparent(u);
        int parent_v=findparent(v);
        if (parent_u==parent_v) return;
        if (size[parent_u]>=size[parent_v]){
            size[parent_u]+=size[parent_v];
            parent[parent_v]=parent[parent_u];
        }
        else{
            size[parent_v]+=size[parent_u];
            parent[parent_u]=parent[parent_v];
        }
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent.resize(n);
        size.resize(n,1);
        for (int i=0;i<n;i++) parent[i]=i;


        for (int i=1;i<n;i++){
            if (nums[i]-nums[i-1]<=maxDiff){
                UnionbySize(i,i-1);
            }
        }

        vector<bool>ans;

        for (auto &q:queries){
            int u=q[0];
            int v=q[1];
            int parent_u=findparent(u);
            int parent_v=findparent(v);
            if (parent_u==parent_v) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};