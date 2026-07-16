class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int>prefd;
        int n=nums.size();
        int maxi=0;
        for (int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            prefd.push_back(gcd(maxi,nums[i]));
        }
        sort(prefd.begin(),prefd.end());
        int i=0;
        int j=n-1;
        long long sum=0;
        while(i<j){
            sum+=gcd(prefd[i],prefd[j]);
            i++;
            j--;
        }
        return sum;
    }
};