#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        long long MOD = 1000000007;
        
        // Edge case: multiplying by 1 changes nothing computationally.
        if (multiplier == 1) {
            vector<int> res(n);
            for (int i = 0; i < n; i++) {
                res[i] = nums[i] % MOD;
            }
            return res;
        }
        
        // Find the maximum element in the initial configuration
        long long max_val = 0;
        for (int x : nums) {
            if (x > max_val) {
                max_val = x;
            }
        }
        
        // Min-heap storing {value, original_index}
        using pii = pair<long long, int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }
        
        // Phase 1: Simulate operations until the array values are "leveled"
        while (k > 0) {
            auto [val, idx] = pq.top();
            
            // Stable round-robin state reached, break simulation early
            if (val >= max_val) {
                break;
            }
            
            pq.pop();
            pq.push({val * multiplier, idx});
            k--;
        }
        
        // Phase 2: Compute full cycles and remaining singles in O(1) mathematical applications
        long long times = k / n;
        long long rem = k % n;
        
        // Standard Binary Exponentiation mapping
        auto power = [&](long long base, long long exp) {
            long long res = 1;
            base %= MOD;
            while (exp > 0) {
                if (exp % 2 == 1) res = (res * base) % MOD;
                base = (base * base) % MOD;
                exp /= 2;
            }
            return res;
        };
        
        long long mult_times = power(multiplier, times);
        long long mult_times_plus_1 = (mult_times * (multiplier % MOD)) % MOD;
        
        vector<int> res(n);
        
        // Extract dynamically matching order layout for leftover operations
        for (int i = 0; i < n; i++) {
            auto [val, idx] = pq.top();
            pq.pop();
            
            // The first `rem` items get times + 1 operations
            long long current_multiplier = (i < rem) ? mult_times_plus_1 : mult_times;
            long long final_val = (val % MOD) * current_multiplier % MOD;
            
            res[idx] = (int)final_val;
        }
        
        return res;
    }
};