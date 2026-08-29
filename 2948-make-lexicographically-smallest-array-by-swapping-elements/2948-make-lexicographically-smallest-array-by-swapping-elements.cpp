class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<pair<int,int>>vec;
        for (int i=0;i<n;i++){
            vec.push_back({nums[i],i});
        }
        sort(vec.begin(),vec.end());

        vector<int>ans(n,0);

        int prev=vec[0].first;
        vector<int>pos;
        pos.push_back(vec[0].second);
        for (int i=1;i<n;i++){
            int next=vec[i].first;
            if ((next-prev)>limit){
                int sz=pos.size();
                sort(pos.begin(),pos.end());

                for (int j=0;j<sz;j++){
                    ans[pos[j]]=vec[i-sz+j].first;
                }

                pos.clear();
            }
            pos.push_back(vec[i].second);
            prev=next;
        }
        
        if (pos.size()>0){
            int sz=pos.size();
            sort(pos.begin(),pos.end());

            for (int j=0;j<sz;j++){
                ans[pos[j]]=vec[n-sz+j].first;
            }
            pos.clear();
        }
        return ans;
    }
};