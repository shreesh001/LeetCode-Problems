class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini=1000;
        int maxi=1;
        for (int i=0;i<nums.size();i++){
            mini=min(nums[i],mini);
            maxi=max(nums[i],maxi);
        }
        return gcd(mini,maxi);
    }
};