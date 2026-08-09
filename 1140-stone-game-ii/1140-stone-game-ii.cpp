class Solution {
public:
    int solve(int op,int ind,int M,vector<int>& piles,vector<vector<vector<int>>>&dp){
        int n=piles.size();
        if (ind>=n) return 0;
        if (dp[op][ind][M]!=-1) return dp[op][ind][M];
        int maxst=(op==0) ? INT_MIN:INT_MAX;
        int stones=0;
        for (int x=1;x<=min((2*M),n-ind);x++){
            stones+=piles[ind+x-1];
            if (op==0){
                maxst=max(maxst,stones+solve(1,ind+x,max(M,x),piles,dp));
            }else{
                maxst=min(maxst,solve(0,ind+x,max(M,x),piles,dp));
            }
        }
        return dp[op][ind][M]=maxst;
    }
    int stoneGameII(vector<int>& piles) {
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(101,vector<int>(101,-1)));
        return solve(0,0,1,piles,dp);
    }
};