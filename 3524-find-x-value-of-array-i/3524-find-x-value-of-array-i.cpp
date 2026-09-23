class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long>res(k,0),prev(k,0);
        int n=nums.size();
        for (int i=0;i<n;i++){
            vector<long long>cur(k,0);
            int currem=nums[i]%k;
            cur[currem]++;
            for (int j=0;j<=k-1;j++){
                int nrem=(j*currem)%k;
                cur[nrem]+=prev[j];
            }
            prev=cur;
            for (int j=0;j<=k-1;j++){
                res[j]+=prev[j];
            }
        }
        return res;
    }
};