class Solution {
public:
    
    long long dp[502][502][2];
    long long mod=1e9+7;
    long long solve(int i,int j,int dir,vector<vector<int>>& grid){

        int m=grid.size();
        int n=grid[0].size();

        if (i>=m || j>=n) return 0;
        if (i==m-1 && j==n-1) return 1;

        if (dp[i][j][dir]!=-1) return dp[i][j][dir];

        long long right=0;
        long long down=0;
        if (grid[i][j]==1){
            if (dir==0){
                right=(right+solve(i,j+1,1,grid))%mod;
            }
            else{
                down=(down+solve(i+1,j,0,grid))%mod;
            }
        }
        else{
            right=(right+solve(i,j+1,1,grid))%mod;
            down=(down+solve(i+1,j,0,grid))%mod;
        }

        return dp[i][j][dir]=(right+down)%mod;;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,grid);
    }
};