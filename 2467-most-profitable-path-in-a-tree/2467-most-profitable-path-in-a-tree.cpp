class Solution {
public:
    vector<vector<int>>adj;
    unordered_map<int,int>BOB_path;
    int max_profit;

    bool dfsBob(int node,int parent,int time){
        BOB_path[node]=time;
        if (node==0) return true;
        for (auto adjnode:adj[node]){
            if (adjnode!=parent){
                if (dfsBob(adjnode,node,time+1)==true) return true;
            }
        }
        BOB_path.erase(node);
        return false;
    }

    void dfsAlice(int node,int parent,int time,int reward,vector<int>& amount){
        if (!BOB_path.count(node) || BOB_path[node]>time){
            reward+=amount[node];
        }
        else if (BOB_path[node]==time){
            reward+=(amount[node]/2);
        }
        
        if (adj[node].size()==1 && node!=0){
            max_profit=max(max_profit,reward);
        }

        for (auto adjnode:adj[node]){
            if (adjnode!=parent){
                dfsAlice(adjnode,node,time+1,reward,amount);
            }
        }

        if (!BOB_path.count(node) || BOB_path[node]>time){
            reward-=amount[node];
        }
        else if (BOB_path[node]==time){
            reward-=(amount[node]/2);
        }

    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=edges.size()+1;
        
        adj.resize(n);
    
        for (auto ed:edges){
            int u=ed[0];
            int v=ed[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        max_profit=-1e5;
        dfsBob(bob,-1,0);
        dfsAlice(0,-1,0,0,amount);
        return max_profit;
    }
};