class Solution {
public:
    int solve(int s,int e,int turn,vector<int>& nums){
        if (s>e) return 0;

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
        return min(start,end);
    }
    bool predictTheWinner(vector<int>& nums) {
        int e=nums.size()-1;
        int ans=solve(0,e,1,nums);
        if (ans>=0) return true;
        return false;
    }
};