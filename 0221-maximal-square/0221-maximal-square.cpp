class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        vector<vector<int>>dp(m,vector<int>(n,0));

        int side=0;
        for (int i=0;i<m;i++){
            dp[i][0]=matrix[i][0]-'0';
            side=max(side,dp[i][0]);
        }
        for (int i=0;i<n;i++){
            dp[0][i]=matrix[0][i]-'0';
            side=max(side,dp[0][i]);
        }

        for (int i=1;i<m;i++){
            for (int j=1;j<n;j++){
                if (matrix[i][j]=='1'){
                    dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                }
                side=max(side,dp[i][j]);
            }
        }
        return (side*side);
    }
};