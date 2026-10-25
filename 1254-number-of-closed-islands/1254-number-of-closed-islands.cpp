class Solution {
public:
    vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis){
        int m=grid.size();
        int n=grid[0].size();
        vis[i][j]=1;
        for (auto d:dir){
            int ni=i+d[0];
            int nj=j+d[1];

            if (ni<0 || nj<0 || ni>=m || nj>=n) continue;

            if (grid[ni][nj]==0 && vis[ni][nj]==0){
                dfs(ni,nj,grid,vis);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));

        for (int i=0;i<n;i++){
            if (grid[0][i]==0 && vis[0][i]==0){
                dfs(0,i,grid,vis);
            }
            if (grid[m-1][i]==0 &&vis[m-1][i]==0){
                dfs(m-1,i,grid,vis);
            }
        }
        for (int i=0;i<m;i++){
            if (grid[i][0]==0 && vis[i][0]==0){
                dfs(i,0,grid,vis);
            }
            if (grid[i][n-1]==0 && vis[i][n-1]==0){
                dfs(i,n-1,grid,vis);
            }
        }
        int res=0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]==0 && vis[i][j]==0){
                    res++;
                    dfs(i,j,grid,vis);
                }
            }
        }

        return res;
    }
};