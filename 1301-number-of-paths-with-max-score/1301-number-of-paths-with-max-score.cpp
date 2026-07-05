class Solution {
public:
    vector<vector<int>>dir={{0,-1},{-1,-1},{-1,0}};
    map<int,int>mpp;
    int solve(int i,int j,vector<string>& board){
        int m=board.size();
        int n=board[0].size();

        if (i==0 && j==0){
            return 0;
        }
        int sum=-1e9;
        for (auto d:dir){
            int ni=i+d[0];
            int nj=j+d[1];
            if (ni<0 || ni>=m || nj<0 || nj>=n) continue;
            if (board[ni][nj]=='X') continue;
            if (board[ni][nj]=='E') return 0;
            int pathsum=(board[ni][nj]-'0')+solve(ni,nj,board);
            sum=max(pathsum,sum);
            mpp[sum]++;
        }
        return sum;
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        int mod=1e9+7;

        vector<vector<int>>dp(n,vector<int>(n,-1));
        vector<vector<int>>paths(n,vector<int>(n,0));

        dp[n-1][n-1]=0;
        paths[n-1][n-1]=1;

        for (int i=n-1;i>=0;i--){
            for (int j=n-1;j>=0;j--){
                if (dp[i][j]==-1 || board[i][j]=='X') continue;
                for (auto d:dir){
                    int ni=i+d[0];
                    int nj=j+d[1];
                    if (ni<0 || nj<0) continue;
                    if (board[ni][nj]=='X') continue;
                    int sc=0;
                    if (board[ni][nj]!='E') sc=board[ni][nj]-'0';
                    int total_sc=dp[i][j]+sc;
                    if (total_sc>dp[ni][nj]){
                        dp[ni][nj]=dp[i][j]+sc;
                        paths[ni][nj]=paths[i][j];
                    }
                    else if (total_sc==dp[ni][nj]){
                        paths[ni][nj]=(paths[ni][nj]+paths[i][j])%mod;
                    }
                }
            }
        }
        if (dp[0][0]==-1) return {0,0};
        return {dp[0][0],paths[0][0]};
    }
};