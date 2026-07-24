class Solution {
public:
    vector<int>seg;
    void buildsegtree(int ind,int l,int r,vector<int>&pair_sum){
        if (l==r){
            seg[ind]=pair_sum[l];
            return;
        }
        int mid=(l+r)/2;
        buildsegtree(2*ind+1,l,mid,pair_sum);
        buildsegtree(2*ind+2,mid+1,r,pair_sum);
        seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);
        return;
    }

    int Range_Maximum(int ind,int s,int e,int l,int r,vector<int>&pair_sum){
        if (e<l || r<s) return INT_MIN;
        if (s<=l && r<=e) return seg[ind];

        int mid=(l+r)/2;

        return max(Range_Maximum(2*ind+1,s,e,l,mid,pair_sum),Range_Maximum(2*ind+2,s,e,mid+1,r,pair_sum));
    }

    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        
        int n=s.size();
        int total_one=0;
        for (auto ch:s){
            if (ch=='1') total_one++;
        }

        vector<int>startInd;
        vector<int>endInd;
        vector<int>size;
        for (int i=0;i<n;){
            if (s[i]=='0'){
                startInd.push_back(i);
                while(i<n && s[i]=='0'){
                    i++;
                }
                endInd.push_back(i-1);
                size.push_back(endInd.back()-startInd.back()+1);
            }
            i++;
        }
        int m=size.size();
        if (m<2){
            return vector<int>(queries.size(),total_one);
        }

        vector<int>pair_sum;
        for (int i=1;i<m;i++){
            pair_sum.push_back(size[i]+size[i-1]);
        }

        vector<int>ans;

        int sz=pair_sum.size();
        seg.assign(4*sz,0);

        buildsegtree(0,0,sz-1,pair_sum);

        for (auto q:queries){
            int l=q[0];
            int r=q[1];

            int max_pairsum=0;
            int low=lower_bound(endInd.begin(),endInd.end(),l)-endInd.begin();
            int high=upper_bound(startInd.begin(),startInd.end(),r)-startInd.begin()-1;
            if (low>=high) {
                ans.push_back(total_one);
                continue;
            }

            int low_size=endInd[low]-max(l,startInd[low])+1;
            int high_size=min(r,endInd[high])-startInd[high]+1;
            
            if (high-low==1){
                max_pairsum=low_size+high_size;
            }
            else if (low<high){
                int pair1=low_size+size[low+1];
                int pair2=high_size+size[high-1];
                int res=Range_Maximum(0,low+1,high-2,0,sz-1,pair_sum);
                max_pairsum=max({res,pair1,pair2});
            }
            ans.push_back(total_one+max_pairsum);

        }
        return ans;
    }
};