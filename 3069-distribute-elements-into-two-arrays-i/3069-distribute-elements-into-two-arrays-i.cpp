class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>nums1,nums2;
        nums1.push_back(nums[0]);
        nums2.push_back(nums[1]);

        for (int i=2;i<n;i++){
            if (nums1.back()>nums2.back()) nums1.push_back(nums[i]);
            else nums2.push_back(nums[i]);
        }

        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        return nums1;
    }
};