class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        long long mod=1e9+7;
        int n=nums.size();

        set<long long>st;
        st.insert(2);
        for (int i=0;i<n;i++){
            long long val=nums[i];
            for (long long j=2;j*j<=nums[i];j++){
                if (val%j==0){
                    st.insert(j);
                    while(val%j==0) val=val/j;
                }
            }
            if (val>1) st.insert(val);
        }

        long long max_sc=-1e15;
        long long best_k=-1;

        for (auto k:st){
            long long curr_max=0;
            long long best_for_k=-1e15;

            for (auto num:nums){
                long long val=num;
                if (num%k!=0) val=-val;

                curr_max+=val;
                best_for_k=max(best_for_k,curr_max);
                if (curr_max<0) curr_max=0;
                
            }
            if (best_for_k>max_sc){
                max_sc=best_for_k;
                best_k=k;
            }
        }
        long long ans=(max_sc*best_k);
        long long res=(ans%mod+mod)%mod;
        return res;
    }
};