class Solution {
public:
    vector<int>upd_parent;
    vector<vector<int>>adj;
    unordered_map<char,vector<int>>mpp;

    void dfs(int node,int parent,string &s){
        mpp[s[node]].push_back(node);
        for (int adjnode:adj[node]){
            char curr_char=s[adjnode];
            if (mpp[curr_char].size()>0){
                upd_parent[adjnode]=mpp[curr_char].back();
            }
            dfs(adjnode,node,s);   
        }
        mpp[s[node]].pop_back();
    }

    vector<int>ans;

    int subtree_size(int node,int parent){
        int sz=1;
        for (auto adjnode:adj[node]){
            sz+=subtree_size(adjnode,node);
        }
        return ans[node]=sz;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=parent.size();

        upd_parent.assign(n,0);
        ans.assign(n,0);
        upd_parent=parent;

        adj.assign(n,vector<int>());
        for (int i=1;i<n;i++){
            int u=parent[i];
            adj[u].push_back(i);
        }

        dfs(0,-1,s);
        adj.clear();
        adj.assign(n,vector<int>());
        for (int i=1;i<n;i++){
            int u=upd_parent[i];
            adj[u].push_back(i);
        }

        subtree_size(0,-1);

        return ans;
    }
};