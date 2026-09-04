class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        for (int i=0;i<n;i++){
            int mini=1e9;
            int maxi=0;
            for (int j=0;j<=i;j++){
                maxi=max(maxi,nums[j]);
            }
            for (int j=i;j<n;j++){
                mini=min(mini,nums[j]);
            }
            if ((maxi-mini)<=k){
                return i;
            }
        }
        return -1;
    }
};