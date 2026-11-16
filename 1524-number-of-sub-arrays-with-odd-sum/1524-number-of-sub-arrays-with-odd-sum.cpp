class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {

        int n=arr.size();
        int sum=0;
        long long ans=0;
        long long mod=1e9+7;
        long long prev1=0,prev2=0;

        int l=0;
        int r=0;
        while(r<n){
            while(r<n && arr[r]%2==0){
                ans+=prev1;
                r++;
            }
            if (r>=n) break;
            long long curr=prev2+(r-l+1);
            ans=(ans+curr)%mod;
            prev2=prev1;
            prev1=curr;
            r++;
            l=r;
        }
        return ans;
    }
};