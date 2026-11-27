class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        map<int,int>f;
        for (auto v:items){
            for (int i=1;i*i<=v[0];i++){
                if (v[0]%i==0){
                    f[i]++;
                    if ((v[0]/i)!=i) f[v[0]/i]++;
                }
            }
        }

        vector<int>dp(budget+1,0);
        for (auto v:items){
            // 0 1 knapscak 
            // for multiple buys which is valid upto to one time only
            for (int j=budget;j>=v[1];j--){
                dp[j]=max(dp[j],dp[j-v[1]]+f[v[0]]);
            }

            // unbound knapsack
            // for using the items unlimited time if already use
            for (int j=v[1];j<=budget;j++){
                dp[j]=max(dp[j],dp[j-v[1]]+1);
            }
        }
        return dp[budget];
    }
};