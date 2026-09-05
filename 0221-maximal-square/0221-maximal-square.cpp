class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>pref(m,vector<int>(n,0));
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                pref[i][j]+=(matrix[i][j]-'0');
                if (j-1>=0) pref[i][j]+=pref[i][j-1];
                if (i-1>=0) pref[i][j]+=pref[i-1][j];
                if (i-1>=0 && j-1>=0) pref[i][j]-=pref[i-1][j-1];
            }
        }

        int maxarea=0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (matrix[i][j]=='0') continue;
                for (int k=0;k<min(m,n);k++){
                    if (i+k>=m || j+k>=n) break;
                    int area=pref[i+k][j+k];
                    if (j-1>=0) area-=pref[i+k][j-1];
                    if (i-1>=0) area-=pref[i-1][j+k];
                    if (j-1>=0 && i-1>=0) area+=pref[i-1][j-1];
                    if (area==((k+1)*(k+1))){
                        maxarea=max(area,maxarea);
                    }
                    else break;
                }
            }
        }
        return maxarea;
    }
};