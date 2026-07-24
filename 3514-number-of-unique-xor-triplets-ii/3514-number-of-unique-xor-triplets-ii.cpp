class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        vector<int>xor_pair;
        unordered_map<int,int>mpp;
        for (int i=0;i<n;i++){
            for (int j=i;j<n;j++){
                int x=nums[i]^nums[j];
                if (mpp.count(x)>0) continue;
                xor_pair.push_back(x);
                mpp[x]=1;
            }
        }
        int m=xor_pair.size();
        int res=0;
        mpp.clear();
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                int x=nums[i]^xor_pair[j];
                if (mpp.count(x)>0) continue;
                res+=1;
                mpp[x]=1;
            }
        }
        return res;
    }
};