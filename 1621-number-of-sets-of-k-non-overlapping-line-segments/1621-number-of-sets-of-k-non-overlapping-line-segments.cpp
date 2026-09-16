class Solution {
public:
    long long mod=1e9+7;
    long long solve(int ind,int srt,int seg,int n,int k,vector<vector<vector<long long>>>&dp){
        if (seg==k) return 1;
        if (ind>=n) return 0;
        if (dp[ind][seg][srt]!=-1) return dp[ind][seg][srt];

        long long res=0;
        if (srt==0){
            res=(res+solve(ind+1,1,seg,n,k,dp))%mod;
            res=(res+solve(ind+1,0,seg,n,k,dp))%mod;
        }
        else{
            res=(res+solve(ind,0,seg+1,n,k,dp))%mod;
            res=(res+solve(ind+1,1,seg,n,k,dp))%mod;
        }
        return dp[ind][seg][srt]=res;
    }
    int numberOfSets(int n, int k) {
        vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(k+2,vector<long long>(2,0)));
        for (int i=0;i<n;i++){
            dp[i][k][0]=1;
            dp[i][k][1]=1;
        }

        for (int i=n-1;i>=0;i--){
            for (int j=k-1;j>=0;j--){
                for (int srt=0;srt<2;srt++){

                    long long res=0;
                    if (srt==0){
                        res=(res+dp[i+1][j][1])%mod;
                        res=(res+dp[i+1][j][0])%mod;
                    }
                    else{
                        res=(res+dp[i][j+1][0])%mod;
                        res=(res+dp[i+1][j][1])%mod;
                    }
                    dp[i][j][srt]=res;
                }
            }
        }
        return dp[0][0][0];
    }
};