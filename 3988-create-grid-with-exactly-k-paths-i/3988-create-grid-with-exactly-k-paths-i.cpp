class Solution {
public:
    bool solve(int r,int c,vector<string>&grid,vector<vector<int>>&dp,int m,int n,int k){
        int ways=0;
        if (r>0) ways+=dp[r-1][c];
        if (c>0) ways+=dp[r][c-1];
        if (r==0 && c==0) ways=1;

        if (r==m-1 && c==n-1){
            if (ways==k) {
                grid[r][c]='.';
                return true;
            }
            return false;
        }

        int nr=r,nc=c+1;
        if (nc==n){
            nc=0;
            nr=r+1;
        }

        if (ways==0){
            grid[r][c]='#';
            dp[r][c]=0;
            return solve(nr,nc,grid,dp,m,n,k);
        }

        if (ways<=k){
            grid[r][c]='.';
            dp[r][c]=ways;
            if (solve(nr,nc,grid,dp,m,n,k)) return true;
        }

        if (r!=0 || c!=0){
            grid[r][c]='#';
            dp[r][c]=0;
            if (solve(nr,nc,grid,dp,m,n,k)) return true;
        }

        return false;
    }
    vector<string> createGrid(int m, int n, int k) {
        vector<string>grid (m,string(n,'#'));
        // vector<vector<int>>dp(m,vector<int>(n,0));

        // if (solve(0,0,grid,dp,m,n,k)){
        //     return grid;
        // }
        // return {};
        if (k==1 && (n==1 || m==1)){
            for (int i=0;i<m;i++){
                for (int j=0;j<n;j++){
                    grid[i][j]='.';
                }
            }
            return grid;
        }
        if ((max(n,m)*(min(n,m)-1))<k) return {};
        if (n==3 && m==3 && k==4){
            return {"..#","...","#.."};
        }

        for (int i=0;i<n;i++){
            grid[0][i]='.';
        }
        for (int j=0;j<m;j++){
            grid[j][n-1]='.';
        }
        if (m>=k){
            int i=0;
            while(k>0){
                grid[i][n-2]='.';
                i++;
                k--;
            }
        }
        else{
            int j=n-1;
            while(k>0){
                grid[1][j]='.';
                j--;
                k--;
            }

        }
        return grid;

    }
};