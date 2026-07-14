class Solution {
public:
    long long mod=1e9+7;
    int dp[201][201][201];
    long long solve(vector<int>&nums,int ind,int seq1,int seq2){
        if (ind==nums.size()){
            if (seq1==seq2) return 1;
            return 0;
        }
        if (dp[ind][seq1][seq2]!=-1) return dp[ind][seq1][seq2];

        long long skip=solve(nums,ind+1,seq1,seq2)%mod;
        long long take1=solve(nums,ind+1,gcd(seq1,nums[ind]),seq2)%mod;
        long long take2=solve(nums,ind+1,seq1,gcd(seq2,nums[ind]))%mod;
        long long res=(skip+take1+take2)%mod;

        return dp[ind][seq1][seq2]=res%mod;
    }
    int subsequencePairCount(vector<int>& nums) {
        // memset(dp,-1,sizeof(dp));
        // return solve(nums,0,0,0)-1;


        // solving using bottom up dp
        
        int n=nums.size();
        int maxval=0;
        for (int i=0;i<n;i++){
            maxval=max(maxval,nums[i]);
        }

        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(maxval+1,vector<int>(maxval+1,0)));

        for (int seq1=0;seq1<=maxval;seq1++){
            for (int seq2=0;seq2<=maxval;seq2++){
                if (seq1!=0 && seq2!=0 && seq1==seq2){
                    dp[n][seq1][seq2]=1;
                }
            }
        }

        for (int i=n-1;i>=0;i--){
            for (int seq1=maxval;seq1>=0;seq1--){
                for (int seq2=maxval;seq2>=0;seq2--){

                    long long skip=dp[i+1][seq1][seq2];
                    long long take1=dp[i+1][gcd(seq1,nums[i])][seq2];
                    long long take2=dp[i+1][seq1][gcd(seq2,nums[i])];

                    dp[i][seq1][seq2]=(skip+take1+take2)%mod;
                }
            }
        }

        return dp[0][0][0];
    }
};