class Solution {
public:
    int dp[505][505];
    int solve(int i,int j,vector<int>&pref){
        if (j-i<=1) return 0;
        if (dp[i][j]!=-1) return dp[i][j];
        int sum=0;
        for (int k=i+1;k<j;k++){
            int sumcurr=0;
            int leftsum=pref[k]-pref[i];
            int rightsum=pref[j]-pref[k];

            if (leftsum<rightsum){
                sumcurr=leftsum;
                sumcurr+=solve(i,k,pref);
            }
            else if (rightsum<leftsum){
                sumcurr=rightsum;
                sumcurr+=solve(k,j,pref);
            }
            else{
                int sum1=leftsum+solve(i,k,pref);
                int sum2=rightsum+solve(k,j,pref);
                sumcurr=max(sum1,sum2);
            }
            sum=max(sum,sumcurr);
        }
        return dp[i][j]=sum;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        memset(dp,-1,sizeof(dp));
        vector<int>pref(n+1,0);
        for (int i=0;i<n;i++){
            pref[i+1]=pref[i]+stoneValue[i];
        }
        return solve(0,n,pref);
    }
};