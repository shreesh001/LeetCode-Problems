class Solution {
public:
// memoization+ recursion approach 
    int solve(int ind,vector<int>& stoneValue,vector<int>&dp){
        int n=stoneValue.size();
        if (ind>=n) return 0;
        if (dp[ind]!=-1) return dp[ind];
        int i=ind;
        int result=INT_MIN;
        result= max(result,stoneValue[i]-solve(i+1,stoneValue,dp));
        if (i+1<n){
            result= max(result,stoneValue[i]+stoneValue[i+1]-solve(i+2,stoneValue,dp));
        }
        if (i+2<n){
            result= max(result,stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-solve(i+3,stoneValue,dp));
        }
        return dp[ind]=result;
    }
    // tabulation code + space optimized 
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int>dp(3,0);
        for (int i=n-1;i>=0;i--){
            int result=INT_MIN;
            result= max(result,stoneValue[i]-dp[0]);
            if (i+1<n){
                result= max(result,stoneValue[i]+stoneValue[i+1]-dp[1]);
            }
            if (i+2<n){
                result= max(result,stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-dp[2]);
            }
            dp[2]=dp[1];
            dp[1]=dp[0];
            dp[0]=result;
        }
        int diff=dp[0];
        if (diff>0){
            return "Alice";
        }
        else if(diff<0){
            return "Bob";
        }
        return "Tie";
    }
};