
class Solution {
public:
    vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges, vector<int>& requiredSignals) {
        vector<vector<pair<int,long long>>> adj(n);

        for (auto &ed : edges) {
            int u = ed[0];
            int v = ed[1];
            long long d = ed[2];

            adj[u].push_back({v, d});
        }

        vector<long long> ans(n, -1);
        vector<int> received(n, 0);

        // {signal arrival time, destination node}
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        ans[0] = 0;

        // Node 0 sends signals at time 0.
        for (auto [v, d] : adj[0]) {
            pq.push({d, v});
        }

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            // Already activated: ignore subsequent signals.
            if (ans[node] != -1) {
                continue;
            }

            received[node]++;

            // Activate after receiving enough signals.
            if (received[node] == requiredSignals[node]) {
                ans[node] = time;

                // Send signals exactly once after activation.
                for (auto [v, d] : adj[node]) {
                    pq.push({time + d, v});
                }
            }
        }

        return ans;
    }
};
