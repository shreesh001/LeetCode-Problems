class Solution {
public:
    vector<int>dp;
    int solve(int n){
        if (n==0) return 0;
        if (dp[n]!=-1) return dp[n];
        int num=1;
        int possible=0;
        while(num*num<=n){
            int moves=1+solve(n-(num*num));
            num++;
            if (moves%2==1) possible=(possible||1);
        }
        return dp[n]=possible;
    }
    bool winnerSquareGame(int n) {
        dp.resize(n+1,-1);
        return solve(n);
    }
};