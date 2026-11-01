class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        
        sort(nums.begin(),nums.end());

        int cum=nums[n-1]-nums[0];
        
        for (int i=n-2;i>=0;i--){
            nums[i]+=cum;
            if (nums[i]-nums[i+1]>0){
                cum+=(nums[i]-nums[i+1]);
            }
            else break;
        }

        return cum;
    }
};