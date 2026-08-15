class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int x=0;
        int cnt0=0;
        for (int i=0;i<n;i++){
            if (nums[i]==0) cnt0++;
            x=x^nums[i];
        }
        if (x==0){
            if (cnt0==n) return 0;
            return n-1;
        }
        return n;
    }
};