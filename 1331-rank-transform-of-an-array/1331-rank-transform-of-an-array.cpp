class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int>arr2=arr;
        sort(arr2.begin(),arr2.end());
        unordered_map<int,int>mpp;
        int rnk=1;
        for (int i=0;i<n;i++){
            if (mpp.find(arr2[i])!=mpp.end()) continue;
            mpp[arr2[i]]=rnk;
            rnk+=1;
        }
        vector<int>ans;
        for (int i=0;i<n;i++){
            ans.push_back(mpp[arr[i]]);
        }
        return ans;
    }
};