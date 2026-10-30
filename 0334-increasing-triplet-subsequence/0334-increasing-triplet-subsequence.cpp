class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();

        vector<long long>ans(3,1e10);
        for (int i=0;i<n;i++){
            long long num=nums[i];

            if (i==n-1){
                if (ans[1]<num){
                    return true;
                }
            }
            if (i==n-2){
                if (num>ans[1]){
                    return true;
                }
                if (num>ans[0] && num<ans[1]){
                    ans[1]=num;
                }
                continue;
            }

            if (ans[0]>num){
                ans[0]=num;
            }
            else if (ans[0]<num && num<ans[1]){
                ans[1]=num;
            }
            else if (ans[1]<num){
                ans[2]=num;
                return true;
            }

        }

        return false;
    }
};