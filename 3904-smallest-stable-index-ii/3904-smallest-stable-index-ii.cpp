class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>>pref(n,{0,1e9});
        int maxi=0;
        int mini=1e9;
        for (int i=0;i<n;i++){
            maxi=max(nums[i],maxi);
            pref[i].first=maxi;
        }
        for (int i=n-1;i>=0;i--){
            mini=min(mini,nums[i]);
            pref[i].second=mini;
        }

        for (int i=0;i<n;i++){
            if ((pref[i].first-pref[i].second)<=k){
                return i;
            }
        }
        return -1;
    }
};