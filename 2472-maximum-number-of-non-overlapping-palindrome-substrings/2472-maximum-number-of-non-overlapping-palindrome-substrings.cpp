class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        vector<vector<bool>> ispali(n, vector<bool>(n, false));

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                if (i == j)
                    ispali[i][j] = true;
                else if (i + 1 == j)
                    ispali[i][j] = (s[i] == s[j]);
                else
                    ispali[i][j] = (s[i] == s[j] && ispali[i + 1][j - 1]);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (ispali[i][j]) {
                    int take = 1 + (j + k <= n ? dp[j + 1][j + k] : 0);
                    int grow = dp[i][j + 1];
                    int slide = dp[i + 1][j + 1];

                    dp[i][j] = max({take, grow, slide});
                } else {
                    int grow = dp[i][j + 1];
                    int slide = dp[i + 1][j + 1];

                    dp[i][j] = max({grow, slide});
                }
            }
        }
        return dp[0][k - 1];
    }
};