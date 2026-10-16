class Solution {
public:
    long long mod=1e9+7;
    vector<long long>sumsegtree,sqsumsegtree,lazytree;

    void updatetree(int s,int e,int i,int l,int r,int val){
        sqsumsegtree[i]+=2*val*sumsegtree[i]+((r-l+1)*val*val);
        sumsegtree[i]+=(r-l+1)*val;
        return;
    }

    void updatequery(int s,int e,int i,int l,int r,int val){
        if (lazytree[i]!=0){
            updatetree(s,e,i,l,r,lazytree[i]);
            if (l!=r){
                lazytree[2*i+1]+=lazytree[i];
                lazytree[2*i+2]+=lazytree[i];
            }
            lazytree[i]=0;
        }

        if (r < s || l > e) {
            return;
        }
        if (l>=s && r<=e){
            updatetree(s,e,i,l,r,val);
            if (l!=r){
                lazytree[2*i+1]+=val;
                lazytree[2*i+2]+=val;
            }
            return;
        }
        int mid=(l+r)/2;
        updatequery(s,e,2*i+1,l,mid,val);
        updatequery(s,e,2*i+2,mid+1,r,val);
        sumsegtree[i]=sumsegtree[2*i+1]+sumsegtree[2*i+2];
        sqsumsegtree[i]=sqsumsegtree[2*i+1]+sqsumsegtree[2*i+2];
        return;
    }
    int sumCounts(vector<int>& nums) {
        int n=nums.size();

        sumsegtree.assign(4*n+4,0);
        sqsumsegtree.assign(4*n+4,0);
        lazytree.assign(4*n+4,0);

        vector<int>lastseen(1e5+1,-1);

        long long res=0;
        for (int i=0;i<n;i++){
            int s=lastseen[nums[i]]+1;
            int e=i;
            updatequery(s,e,0,0,n-1,1);
            res=(res+sqsumsegtree[0])%mod;
            lastseen[nums[i]]=i;
        }
        return res;


    }
};