class Solution {
public:
    int dp[100005];
    int solve(int ind,vector<int>&pref){
        int n=pref.size();
        if (ind==n-2) return pref[ind+1];
        if (dp[ind]!=-1) return dp[ind];

        int score=0;
        int nottake=solve(ind+1,pref);
        int take=(pref[ind+1])-solve(ind+1,pref);
        score=max(take,nottake);
        return dp[ind]=score;
    }
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<int>pref(n,0);
        pref[0]=stones[0];
        for (int i=1;i<n;i++){
            pref[i]=pref[i-1]+stones[i];
        }
        
        int best=pref[n-1];
        for (int i=n-2;i>=1;i--){
            best=max(best,pref[i]-best);
        }
        return best;


    }
};