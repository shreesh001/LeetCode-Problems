class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans=0;
        for (int l=1;l<=n;l++){
            for (int i=0;i+l-1<n;i++){
                int j=i+l-1;
                if (l==1){
                    dp[i][j]=1;
                    ans+=1;
                } 
                else if (l==2){
                    if (s[i]==s[j]){
                        dp[i][j]=1;
                        ans+=1;
                    }else{
                        dp[i][j]=0;
                    }
                }
                else{
                    if (s[i]!=s[j]){
                        dp[i][j]=0;
                    }
                    else if (s[i]==s[j]){
                        if (dp[i+1][j-1]==1) {
                            dp[i][j]=1;
                            ans+=1;
                        }
                        else if (dp[i+1][j-1]==0) dp[i][j]=0;
                    }
                }
            }
        }
        return ans;
    }
};