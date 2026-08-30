class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int maxi=-1e5;
        int mini=1e5;
        int maxi_ind=-1;
        int mini_ind=-1;

        for (int i=0;i<n;i++){
            if (nums[i]<mini){
                mini=nums[i];
                mini_ind=i;
            }
            if (nums[i]>maxi){
                maxi=nums[i];
                maxi_ind=i;
            }
        }
        int ans=(n-max(maxi_ind,mini_ind))+min(maxi_ind,mini_ind)+1;
        int res=min({max(maxi_ind,mini_ind)+1,n-min(maxi_ind,mini_ind),ans});
        return res;
    }
};