class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for (int i=0;i<n;i++){
            int n=nums[i];
            int sum=0;
            while(n>0){
                int rem=n%10;
                sum+=rem;
                n=n/10;
            }
            if (sum==i) return i;
        }
        return -1;
    }
};