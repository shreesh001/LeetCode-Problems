class Solution {
public:
    int dp[21][21][2];
    int solve(int s,int e,int turn,vector<int>& nums){
        if (s>e) return 0;
        if (dp[s][e][turn]!=-1) return dp[s][e][turn];
        int start=-1e7;
        int end=-1e7;
        if (turn==1){
            start=nums[s]+solve(s+1,e,0,nums);
            end=nums[e]+solve(s,e-1,0,nums);
            return max(start,end);
        }
        else{
            start=-nums[s]+solve(s+1,e,1,nums);
            end=-nums[e]+solve(s,e-1,1,nums);
        }
        return dp[s][e][turn]=min(start,end);
    }
    bool predictTheWinner(vector<int>& nums) {
        int e=nums.size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,e-1,1,nums);
        if (ans>=0) return true;
        return false;
    }
};