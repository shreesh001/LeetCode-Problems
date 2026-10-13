class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        if (n==1) return nums[0]*nums[0];
        for (int i=0;i<n;i++) nums[i]=abs(nums[i]);
        sort(nums.begin(),nums.end());
        int end=n/2;
        for (int i=0;i<n;i++){
            if (i<end){
                ans-=(1ll*nums[i]*1ll*nums[i]);
            }
            else ans+=(1ll*nums[i]*1ll*nums[i]);
        }

        return ans;
    }
};