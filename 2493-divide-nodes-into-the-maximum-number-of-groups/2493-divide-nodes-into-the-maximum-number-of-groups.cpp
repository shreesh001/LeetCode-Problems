class Solution {
public:
    vector<vector<int>>adj;
    vector<int>degree;
    vector<int>vis;
    bool checkdfs(int node,int num){
        vis[node]=num;
        if (num==1) num=2;
        else num=1;
        for (auto adjnode:adj[node]){
            if (!vis[adjnode]){
                if (checkdfs(adjnode,num)==false) return false;
            }
            else if (vis[adjnode]!=num) return false;
        }
        return true;
    }
    
    int findlevel(int node){
        int height=0;
        queue<int>q;
        q.push(node);
        vis[node]=1;
        while(!q.empty()){
            int sz=q.size();
            height+=1;
            for (int i=0;i<sz;i++){
                auto node=q.front();
                q.pop();
                for (auto adjnode:adj[node]){
                    if(!vis[adjnode]){
                        q.push(adjnode);
                        vis[adjnode]=1;
                    } 
                }
            }
        }
        return height;
    }

    int dfs(int node,vector<int>&max_level){
        vis[node]=1;
        int res=max_level[node];
        for (auto adjnode:adj[node]){
            if (!vis[adjnode]){
                res=max(res,dfs(adjnode,max_level));
            }
        }
        return res;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        degree.assign(n,0);
        vis.assign(n,0);
        for (auto ed:edges){
            int u=ed[0]-1;
            int v=ed[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        // check for bipartite ness 
        for (int i=0;i<n;i++){
            if (vis[i]==0){
                if (checkdfs(i,1)==false) return -1;
            }
        }

        // find max level for each node so that we can divide into max no of group
        vector<int>max_level(n,0);
        for (int i=0;i<n;i++){
            vis.assign(n,0);
            max_level[i]=max(max_level[i],findlevel(i));
        }

        vis.assign(n,0);

        // connecting the max group of different component
        int max_group=0;
        for (int i=0;i<n;i++){
            if (vis[i]==0){
                max_group+=dfs(i,max_level);
            }
        }


        return max_group;
        
        

        




    }
};