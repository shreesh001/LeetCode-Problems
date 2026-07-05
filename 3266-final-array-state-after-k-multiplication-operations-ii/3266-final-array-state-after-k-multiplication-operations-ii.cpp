class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    long long modPow(long long base, long long exp) {
        long long ans = 1;
        base %= MOD;

        while (exp > 0) {
            if (exp & 1)
                ans = ans * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }

        return ans;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {

        if (multiplier == 1)
            return nums;

        int n = nums.size();

        long long mx = 0;
        for (int x : nums)
            mx = max(mx, (long long)x);

        using Node = pair<long long, int>;

        priority_queue<Node, vector<Node>, greater<Node>> pq;

        for (int i = 0; i < n; i++)
            pq.push({nums[i], i});

        while (k > 0 && pq.top().first < mx) {
            auto cur = pq.top();
            pq.pop();

            cur.first *= 1LL * multiplier;

            pq.push(cur);
            k--;
        }

        vector<int> ans(n);

        long long each = k / n;
        int extra = k % n;

        vector<Node> order;

        while (!pq.empty()) {
            order.push_back(pq.top());
            pq.pop();
        }

        for (int i = 0; i < n; i++) {
            long long value = order[i].first % MOD;

            long long times = each;
            if (i < extra)
                times++;

            value = value * modPow(multiplier, times) % MOD;

            ans[order[i].second] = (int)value;
        }

        return ans;
    }
};