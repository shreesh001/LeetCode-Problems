class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));

        int maxlen=0;
        int left=-1;
        int right=-1;
        for (int l=1;l<=n;l++){
            for (int i=0;i+l-1<n;i++){
                int j=i+l-1;
                if (l==1) dp[i][j]=1;
                else if (l==2){
                    if (s[i]==s[j]) dp[i][j]=2;
                }
                else{
                    if (s[i]==s[j] && dp[i+1][j-1]>=1) dp[i][j]=2+dp[i+1][j-1]; 
                }

                if (dp[i][j]>maxlen){
                    maxlen=dp[i][j];
                    left=i;
                    right=j;
                }
            }
        }
        string ans="";
        for (int i=left;i<=right;i++){
            ans+=s[i];
        }
        return ans;

    }
};