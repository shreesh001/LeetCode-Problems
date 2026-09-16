class Solution {
public:
    int solve(int dir1,int dir2,vector<pair<int,int>>&ind,set<pair<int,int>>&st,int n){
        int maxi=0;
        for (int i=0;i<=n;i++){
            for (int j=0;j<=n;j++){
                int cnt=0;
                for (int k=0;k<ind.size();k++){
                    auto [x,y]=ind[k];
                    int newx=x+(dir1*i);
                    int newy=y+(dir2*j);
                    if (st.find({newx,newy})!=st.end()) cnt++;
                }
                maxi=max(maxi,cnt);
            }
        }
        return maxi;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector<pair<int,int>>ind;
        set<pair<int,int>>st;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (img1[i][j]==1) ind.push_back({i,j});
                if (img2[i][j]==1) st.insert({i,j});
            }
        }

        int res1=solve(-1,-1,ind,st,n);
        int res2=solve(-1,1,ind,st,n);
        int res3=solve(1,-1,ind,st,n);
        int res4=solve(1,1,ind,st,n);

        return max({res1,res2,res3,res4});

    }
};