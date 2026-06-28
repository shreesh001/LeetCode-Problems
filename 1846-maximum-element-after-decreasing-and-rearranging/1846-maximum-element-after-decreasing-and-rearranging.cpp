class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n=arr.size();
        map<int,int>mpp;
        for (int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        int res=0;
        for (auto &[el,rep]:mpp){
            res=min(el,res+rep);
        }
        return res;
    }
};