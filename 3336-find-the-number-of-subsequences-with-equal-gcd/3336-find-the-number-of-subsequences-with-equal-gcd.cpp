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
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,0,0)-1;
    }
};