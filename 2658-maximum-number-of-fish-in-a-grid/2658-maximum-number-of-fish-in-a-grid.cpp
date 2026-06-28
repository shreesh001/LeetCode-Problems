class Solution {
public:
    class dsu{
        public:
        vector<int>parent;
        vector<int>size;
        dsu(int n){
            parent.resize(n);
            size.resize(n);
            for (int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        int findparent(int node){
            if (node==parent[node]) return node;
            return parent[node]=findparent(parent[node]);
        }
        void UnionBySize(int u,int v){
            int pu=findparent(u);
            int pv=findparent(v);
            if (pu==pv) return;
            if (size[pu]>=size[pv]){
                parent[pv]=pu;
                size[pu]+=size[pv];
            }else{
                parent[pu]=pv;
                size[pv]+=size[pu];
            }
        }
    };
    
    int findMaxFish(vector<vector<int>>& grid) {

        vector<vector<int>>dir={{1,0},{0,1}};
        // only need the right and down direction other direction are redundent

        // dsu initialization 
        int m=grid.size();
        int n=grid[0].size();
        int sz=m*n;
        dsu disjointset(sz);
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                disjointset.size[i*n+j]=grid[i][j];
            }
        }

        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]==0) continue;
                for (auto d:dir){
                    int nr=i+d[0];
                    int nc=j+d[1];
                    if (nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]!=0){
                        int u=i*n+j;
                        int v=nr*n+nc;
                        disjointset.UnionBySize(u,v);
                    }
                }
            }
        }
        int maxsize=0;
        for (int i=0;i<m*n;i++){
            maxsize=max(maxsize,disjointset.size[i]);
        }
        return maxsize;

    }
};