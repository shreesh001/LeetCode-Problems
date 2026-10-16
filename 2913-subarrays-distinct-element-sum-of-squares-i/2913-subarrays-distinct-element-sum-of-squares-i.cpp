class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        for (int i=0;i<n;i++){
            map<int,int>mpp;
            for (int j=i;j<n;j++){
                mpp[nums[j]]++;
                ans+=(mpp.size()*mpp.size());
            }
        }
        return ans;
    }
};