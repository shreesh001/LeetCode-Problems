class Solution {
public:
    int solve(int len1,int len2,vector<int>& nums){
        int n=nums.size();
        int maxi=0;
        int fst_sum=0;
        int left=0;
        for (int right=0;right<n;right++){
            fst_sum+=nums[right];
            if (right-left+1<len1) continue;
            int sec_sum=0;
            int start=right+1;
            for (int j=start;j<n;j++){
                sec_sum+=nums[j];
                if (j-start+1==len2){
                    maxi=max(maxi,(fst_sum+sec_sum));
                    sec_sum-=nums[start];
                    start++;
                }
            }
            fst_sum-=nums[left];
            left++;
        }
        return maxi;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int ans1=solve(firstLen,secondLen,nums);
        int ans2=solve(secondLen,firstLen,nums);
        return max(ans1,ans2);
    }
};