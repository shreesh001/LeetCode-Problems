class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int sum=nums[0];
        for (int i=1;i<n;i++){
            if (nums[i]==nums[i-1]+1){
                sum+=nums[i];
            }
            else break;
        }

        unordered_map<int,int>present;
        for (int i=0;i<n;i++){
            present[nums[i]]=1;
        }

        while(present.count(sum)>0){
            sum++;
        }
        return sum;
    }
};