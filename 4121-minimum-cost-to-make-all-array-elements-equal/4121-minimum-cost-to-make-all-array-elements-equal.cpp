class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n=nums.size();
        long long cost=LLONG_MAX;
        for (int i=1;i<n-1;i++){
            long long pref=0,suff=0;

            if (i==1 && nums[i]==nums[i-1]) pref=0;
            else pref=1ll*i*nums[i];

            while(i<n-1 && nums[i]==nums[i+1]){
                i++;
            }

            if (i==n-2 && nums[i]==nums[i+1]) suff=0;
            else suff=1ll*(n-i-1)*nums[i];

            cost=min(cost,suff+pref);
        }
        return cost;
    }
};