class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });

        int q = queries.size();
        vector<pair<int,int>> qs(q);
        for (int i = 0; i < q; i++) qs[i] = {queries[i], i};
        sort(qs.begin(), qs.end());

        vector<int> freq(n + 1, 0), ans(q);
        int active = 0;
        int l = 0, r = 0, m = logs.size();

        for (auto& [qt, idx] : qs) {
            // add logs with time <= qt
            while (r < m && logs[r][1] <= qt) {
                if (freq[logs[r][0]]++ == 0) active++;
                r++;
            }
            // remove logs with time < qt - x
            while (l < r && logs[l][1] < qt - x) {
                if (--freq[logs[l][0]] == 0) active--;
                l++;
            }
            ans[idx] = n - active;
        }
        return ans;
    }
};