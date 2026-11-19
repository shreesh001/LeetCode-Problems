class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n=nums.size();
        if (n==3){
            return 0;
        }
        sort(nums.begin(),nums.end());

        int min_range=INT_MAX;
        for (int i=0;i<3;i++){
            int range=nums[n-3+i]-nums[i];
            min_range=min(range,min_range);
        }
        return min_range;
    }
};