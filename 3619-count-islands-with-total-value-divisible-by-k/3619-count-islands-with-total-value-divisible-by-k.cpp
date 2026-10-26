class Solution {
public:
    vector<vector<int>>dir{{0,-1},{0,1},{-1,0},{1,0}};
    int dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,int k){
        int m=grid.size();
        int n=grid[0].size();
        vis[i][j]=1;
        int val=grid[i][j];
        for (auto &d:dir){
            int ni=i+d[0];
            int nj=j+d[1];
            if (ni<0 || ni>=m || nj<0 || nj>=n) continue;

            if (vis[ni][nj]==0 && grid[ni][nj]!=0){
                val=(val+dfs(ni,nj,grid,vis,k))%k;
            }
        }
        return val%k;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));

        int rs=0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (vis[i][j]==0 && grid[i][j]!=0){
                    int total=dfs(i,j,grid,vis,k);
                    if (total==0) rs+=1;
                }
            }  
        }
        return rs;
    }
};