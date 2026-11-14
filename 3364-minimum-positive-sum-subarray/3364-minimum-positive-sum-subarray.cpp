class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();

        vector<int>pref(n+1,0);
        pref[1]=nums[0];
        for (int i=1;i<n;i++){
            pref[i+1]=pref[i]+nums[i];
        }

        int ans=1e9;
        for (int i=1;i<=n;i++){
            for (int j=i;j<=n;j++){
                int len=j-i+1;
                if (len>=l && len<=r){
                    int val=pref[j]-pref[i-1];
                    if (val>0){
                        ans=min(ans,val);
                    }
                }
            }
        }

        if (ans==1e9) return -1;
        return ans;
    }
};