class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int>dp(n+1,n+1);
        int minLen=n+1;
        int mini=n+1;
        unordered_map<int,int>mpp;
        int sum=0;
        mpp[sum]=0;
        for (int i=1;i<=n;i++){
            sum+=arr[i-1];

            int remove=sum-target;

            if (mpp.find(remove)!=mpp.end()){
                int srt_prev=mpp[remove];
                int currlen=i-srt_prev;
                mini=min(currlen,mini);
                int secondlen=dp[srt_prev];
                minLen=min(minLen,currlen+secondlen);
            }
            dp[i]=mini;
            mpp[sum]=i;
        }

        if (minLen>n) return -1;
        return minLen;
    }
};