class Solution {
public:
    int binary_search(int l,vector<pair<int,int>>&ind,int end_val){
        int low=l;
        int high=ind.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;

            if (ind[mid].first>end_val){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        unordered_map<int,int>mpp;
        int sum=0;
        mpp[sum]=-1;
        vector<pair<int,int>>ind;
        for (int i=0;i<n;i++){
            sum+=arr[i];
            int val=sum-target;

            if (mpp.find(val)!=mpp.end()){
                ind.push_back({mpp[val]+1,i});
            }
            mpp[sum]=i;
        }

        int m=ind.size();
        if (m==0) return -1;

        sort(ind.begin(),ind.end());
        
        vector<int>preflen(m,0);
        preflen[m-1]=ind[m-1].second - ind[m-1].first + 1;
        for (int i=m-2;i>=0;i--){
            int currlen=ind[i].second-ind[i].first+1;
            preflen[i]=min(currlen,preflen[i+1]);
        }

        int minilen=n+1;
        for (int i=0;i<m-1;i++){

            int srt_val=ind[i].first;
            int end_val=ind[i].second;
            int len=end_val-srt_val+1;

            auto index=binary_search(i+1,ind,end_val);
            if (index==-1) continue;

            minilen=min(minilen,len+preflen[index]);
        }
        if (minilen==n+1) minilen=-1;
        return minilen;
    }
};