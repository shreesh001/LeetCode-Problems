class Solution {
public:
    vector<vector<pair<int,int>>>adj;
   
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        adj.resize(n);
        for (auto ed:edges){
            int u=ed[0];
            int v=ed[1];
            int w=ed[2];
            adj[u].push_back({v,w});
        }
        
        vector<vector<int>>dist(n,vector<int>(k+1,1e9));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,0,1});
        dist[0][1]=0;
        
        while(!pq.empty()){
            auto vec=pq.top();
            pq.pop();
            int d=vec[0];
            int node=vec[1];
            int times=vec[2];
            int ch=labels[node]-'a';
            
            if (node==n-1) return d;

            for (auto it:adj[node]){
                int adjnode=it.first;
                int wt=it.second;
                int ch_adj=labels[adjnode]-'a';
                if (ch==ch_adj){
                    if ( times+1<=k && dist[adjnode][times+1]>d+wt){
                        dist[adjnode][times+1]=d+wt;
                        pq.push({dist[adjnode][times+1],adjnode,times+1});
                    }
                }
                else{ 
                    if (dist[adjnode][1]>d+wt){
                        dist[adjnode][1]=d+wt;
                        pq.push({dist[adjnode][1],adjnode,1});
                    }
                }
                
            }
        }
        return -1;
    }
};