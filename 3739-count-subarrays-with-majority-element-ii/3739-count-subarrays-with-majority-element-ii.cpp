class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        long long res=0;
        unordered_map<long long,long long>mpp;
        mpp[0]+=1;
        long long cumsum=0;
        long long validleftpt=0;
        for (int i=0;i<nums.size();i++){
            if (nums[i]==target){
                validleftpt+=mpp[cumsum];
                cumsum+=1;
            }
            else{
                cumsum-=1;
                validleftpt-=mpp[cumsum];
            }
            mpp[cumsum]+=1;
            res+=validleftpt;
        }
        return res;
    }
};