class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        vector<int>ans(10,0);
        int n=nums.size();
        for (int i=0;i<n;i++){
            int num=nums[i];
            int larg=0,sm=9;
            while(num>0){
                int dig=num%10;
                larg=max(larg,dig);
                sm=min(sm,dig);
                num=num/10;
            }
            int diff=larg-sm;
            ans[diff]+=nums[i];
        }
        int res=0;
        for (int i=9;i>=0;i--){
            if (ans[i]!=0) return ans[i];
        }
        return res;
    }
    
};