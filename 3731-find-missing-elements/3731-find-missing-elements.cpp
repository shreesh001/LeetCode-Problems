class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>ans;
        for (int i=1;i<n;i++){
            if (nums[i]-nums[i-1]>1){
                for (int low=nums[i-1]+1;low<nums[i];low++){
                    ans.push_back(low);
                }
            }
        }
        return ans;
    }
};