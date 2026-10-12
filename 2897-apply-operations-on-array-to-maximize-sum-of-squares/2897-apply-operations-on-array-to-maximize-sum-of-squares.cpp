class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int mod=1e9+7;
        int n=nums.size();
        vector<int>digit(32,0);

        for (int i=0;i<n;i++){
            int num=nums[i];
            for (int j=0;j<=31;j++){
                int bit=num&(1<<j);
                if (bit>0) digit[j]+=1;
            }
        }
        
        long long sum=0;
        for (int num=1;num<=k;num++){
            long long no=0;
            for (int j=0;j<=31;j++){
                if (digit[j]>0){
                    digit[j]--;
                    no+=(1ll<<j);
                }
            }
            sum=(sum+(no*no))%mod;
        }

        return sum;
    }
};