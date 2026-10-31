class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();

        vector<int>copy=nums;

        sort(copy.begin(),copy.end());

        int first=-1;
        int last=-2;

        for (int i=0;i<n;i++){
            if (copy[i]!=nums[i]){
                first=i;
                break;
            }
        }

        for (int i=n-1;i>=0;i--){
            if (copy[i]!=nums[i]){
                last=i;
                break;
            }
        }

        int len=last-first+1;
        return len;
    }
};