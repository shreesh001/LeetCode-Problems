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
        vector<vector<vector<long long>>>dp(n,vector<vector<long long>>(k+1,vector<long long>(2,-1)));
        return solve(0,0,0,n,k,dp);
    }
};