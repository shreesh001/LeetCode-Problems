class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        unordered_map<int,int>mpp_suff;
        mpp_suff[0]=0;
        int ans=n+1;
        int suff=0;
        for (int i=0;i<n;i++){
            suff+=nums[n-1-i];

            if (suff==x){
                ans=min(ans,i+1);
            }

            mpp_suff[suff]=i+1;
        }

        int pref=0;
        for (int i=0;i<n;i++){
            pref+=nums[i];
            if (pref>x) break;
            int rem=x-pref;

            if (mpp_suff.find(rem)!=mpp_suff.end()){
                ans=min(ans,i+1+mpp_suff[rem]);
            }
        }

        if (ans==n+1) ans=-1;
        return ans;
    }
};