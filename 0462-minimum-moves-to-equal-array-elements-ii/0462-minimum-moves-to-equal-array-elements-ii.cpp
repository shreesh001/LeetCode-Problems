class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        if (n==1) return 0;
        sort(nums.begin(),nums.end());


        int avg1=nums[n/2];
        int avg2=nums[(n/2)-1];

        int moves1=0;
        int moves2=0;
        for (int i=0;i<n;i++){
            moves1+=abs(avg1-nums[i]);
            moves2+=abs(avg2-nums[i]);
        }

        return min(moves1,moves2);

    }
};