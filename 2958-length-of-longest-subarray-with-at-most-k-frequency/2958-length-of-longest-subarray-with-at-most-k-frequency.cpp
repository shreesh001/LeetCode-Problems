class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int n=nums.size();
        int l=0;
        int r=0;
        int maxlen=0;
        while(r<n){
            freq[nums[r]]++;
            while(l<=r && freq[nums[r]]>k){
                freq[nums[l]]--;
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};