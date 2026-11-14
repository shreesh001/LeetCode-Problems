class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxi_len=1;
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                if (nums[j-1]>=nums[j]){
                    break;
                }
                maxi_len=max(maxi_len,j-i+1);
            }
            for (int j=i+1;j<n;j++){
                if (nums[j-1]<=nums[j]){
                    break;
                }
                maxi_len=max(maxi_len,j-i+1);
            }
        }

        return maxi_len;
    }
};