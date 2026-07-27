class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {

        int n=nums.size();
        int i=0;
        long long swaps=0;
        long long mod=1e9+7;
        long long cnt1=0,cnt2=0;
        while(i<n){
            if (nums[i]<a){
                swaps=(swaps+cnt1+cnt2)%mod;
            }
            else if (nums[i]>=a && nums[i]<=b){
                swaps=(swaps+cnt2)%mod;
                cnt1++;
            }
            else{
                cnt2++;
            }
            i++;
        }
        return swaps;
    }
};