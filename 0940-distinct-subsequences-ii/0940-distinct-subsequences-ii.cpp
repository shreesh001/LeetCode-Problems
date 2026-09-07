class Solution {
public:
    int distinctSubseqII(string s) {
        int mod=1e9+7;
        int n=s.size();
        vector<int>prev(n,0); 
        vector<int>prevInd(26,0);
        for (int i=0;i<n;i++){
            int c=s[i]-'a';
            int pInd=prevInd[c];
            prev[i]=pInd;
            prevInd[c]=i+1;
        }  

        vector<long long>dp(n+1,0);
        dp[0]=1;
        for (long long i=1;i<=n;i++){
            long long ch=s[i-1]-'a';
            dp[i]=(2*dp[i-1])%mod;
            long long dup=0;
            if (prev[i-1]-1>=0) dup=dp[prev[i-1]-1];

            dp[i]=(dp[i]-dup+mod)%mod;
        }
        return (dp[n]-1+mod)%mod;
    }
};