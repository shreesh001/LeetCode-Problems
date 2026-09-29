class Solution {
public:
    int dp[101][101][205];
    bool solve(int i,int j,vector<vector<char>>&grid,int sum){
        int m=grid.size();
        int n=grid[0].size();
        if (sum<=0) return false;
        if (i>=m || j>=n) return false;

        if (i==m-1 && j==n-1 && grid[i][j]==')'){
            sum-=1;
            if (sum==1) return true;
            else return false;
        }

        bool res=false;

        if (grid[i][j]=='(') sum+=1;
        else sum-=1;
        
        if (dp[i][j][sum]!=-1) return dp[i][j][sum];

        // right moves
        bool right=res||solve(i,j+1,grid,sum);

        //down moves
        bool down=res||solve(i+1,j,grid,sum);

        res= (right || down);

        return dp[i][j][sum]=res;
    }
    bool hasValidPath(vector<vector<char>>& grid) {

        int m=grid.size();
        int n=grid[0].size();

        if (grid[0][0]==')' || grid[m-1][n-1]=='(') return false;

        memset(dp,-1,sizeof(dp));

        return solve(0,0,grid,1); 

    }
};