class Solution {
public:
    struct Node {
        long long score;
        vector<int> ids;
        bool valid;

        Node() : score(0), valid(false) {}
        Node(long long s, vector<int> v) : score(s), ids(std::move(v)), valid(true) {}
    };

    bool better(const Node& a, const Node& b) {
        if (!a.valid) return false;
        if (!b.valid) return true;

        if (a.score != b.score) return a.score > b.score;

        return a.ids < b.ids;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        const int K = 4;

        vector<array<long long, 4>> a(n);

        for (int i = 0; i < n; ++i) {
            a[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
            return x[1] < y[1];
        });

        vector<long long> ends(n);
        for (int i = 0; i < n; ++i) {
            ends[i] = a[i][1];
        }

        vector<vector<Node>> dp(K + 1, vector<Node>(n + 1));

        for (int i = 0; i <= n; ++i) {
            dp[0][i] = Node(0, {});
        }

        for (int i = 1; i <= n; ++i) {
            long long l = a[i - 1][0];
            long long w = a[i - 1][2];
            int idx = (int)a[i - 1][3];

            int p = lower_bound(ends.begin(), ends.begin() + (i - 1), l) - ends.begin();

            for (int k = 1; k <= K; ++k) {
                dp[k][i] = dp[k][i - 1];

                if (dp[k - 1][p].valid) {
                    vector<int> ids = dp[k - 1][p].ids;

                    ids.push_back(idx);

                    sort(ids.begin(), ids.end());

                    Node take(dp[k - 1][p].score + w, std::move(ids));

                    if (better(take, dp[k][i])) {
                        dp[k][i] = std::move(take);
                    }
                }
            }
        }

        Node ans;

        for (int k = 1; k <= K; ++k) {
            if (better(dp[k][n], ans)) {
                ans = dp[k][n];
            }
        }

        return ans.ids;
    }
};