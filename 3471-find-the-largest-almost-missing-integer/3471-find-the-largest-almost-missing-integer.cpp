class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        if (k==n){
            return *max_element(nums.begin(),nums.end());
        }
        if (k==1){
            map<int,int>freq;
            for (int i=0;i<n;i++){
                freq[nums[i]]++;
            }
            int maxi=-1;
            for (auto it:freq){
                if (it.second==1) maxi=max(maxi,it.first);
            }
            return maxi;
        }
        int num1=nums[0];
        int num2=nums[n-1];
        if (num1==num2) return -1;
        bool f1=false,f2=false;
        for (int i=1;i<n-1;i++){
            if (nums[i]==num1) f1=true;
            if (nums[i]==num2) f2=true;
        }

        if (f1 && f2) return -1;
        if (f1) return num2;
        if (f2) return num1;
        return max(num1,num2);
    }
};