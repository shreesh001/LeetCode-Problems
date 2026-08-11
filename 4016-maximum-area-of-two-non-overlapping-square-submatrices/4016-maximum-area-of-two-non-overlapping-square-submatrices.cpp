class Solution {
public:
    void buildpref(vector<vector<int>>& mat,vector<vector<int>>&pref){

        int m=mat.size();
        int n=mat[0].size();

        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                pref[i][j]+=mat[i][j];
                if (i-1>=0) pref[i][j]+=pref[i-1][j];
                if (j-1>=0) pref[i][j]+=pref[i][j-1];
                if (i-1>=0 && j-1>=0) pref[i][j]-=pref[i-1][j-1];
            }
        }
    }

    int getsum(int r,int c,int k,vector<vector<int>>&pref){
        int toprow=r-k+1;
        int leftcol=c-k+1;
        if (toprow<0 || leftcol<0) return 0;

        int sum=pref[r][c];
        if (toprow-1>=0) sum-=pref[toprow-1][c];
        if (leftcol-1>=0) sum-=pref[r][leftcol-1];
        if (toprow-1>=0 && leftcol-1>=0) sum+=pref[toprow-1][leftcol-1];

        return sum;
    }

    bool ispossible(vector<vector<int>>&pref,int m,int n,int k){
        
        int minRow=m;
        int maxRow=0;
        int minCol=n;
        int maxCol=0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (getsum(i,j,k,pref)==k*k){
                    minRow=min(i,minRow);
                    maxRow=max(i,maxRow);
                    minCol=min(j,minCol);
                    maxCol=max(j,maxCol);
                }
            }
        }

        if ((minRow+k<=maxRow) || (minCol+k<=maxCol)) return true;
        return false;
    }

    int maxArea(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>pref(m,vector<int>(n,0));

        buildpref(mat,pref);

        int low=0;
        int high=min(n,m);
        int ans=0;

        while(low<=high){
            int mid=(low+high)/2;
            if (ispossible(pref,m,n,mid)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }

        return (ans*ans);

    }
};