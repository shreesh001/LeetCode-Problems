class Solution {
public:
    vector<int>subarray;
    vector<int>res;
    vector<vector<int>>helperdp;
    int helper(int k,int count,int ind){
        if (count==0) return 0;
        if (ind>=subarray.size()) return -1e8;
        if (helperdp[ind][count]!=-1e8) return helperdp[ind][count];
        int take=subarray[ind]+helper(k,count-1,ind+k);
        int notake=helper(k,count,ind+1);

        return helperdp[ind][count]=max(take,notake);
    }
    void solve(int k,int count,int ind){
        if (count==0) return;
        if (ind>=subarray.size()) return;

        int take=subarray[ind]+helper(k,count-1,ind+k);
        int nottake=helper(k,count,ind+1);

        if (take>=nottake){
            res.push_back(ind);
            solve(k,count-1,ind+k);
        }
        else solve(k,count,ind+1);

    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {

        int n=nums.size();
        
        int sum=0;
        for (int i=0;i<n;i++){
            sum+=nums[i];
            if (i>=k) sum -=nums[i-k];
            if (i>=k-1) subarray.push_back(sum);
        }

        helperdp.resize(n,vector<int>(4,-1e8));

        solve(k,3,0);
        return res;


    }
};