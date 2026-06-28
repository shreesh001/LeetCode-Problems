class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n=arr.size();
        vector<int>cnt(n+1,0);
        for (int i=0;i<n;i++){
            cnt[min(n,arr[i])]++;
        }
        int res=0;
        for (int i=1;i<cnt.size();i++){
            res=min(i,res+cnt[i]);
        }
        return res;
    }
};