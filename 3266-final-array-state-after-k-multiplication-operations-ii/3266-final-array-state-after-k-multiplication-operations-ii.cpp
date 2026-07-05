#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long modpow(long long base, long long exp, long long mod) {
        base %= mod;
        if (base < 0) base += mod;
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = (long long)((__int128)result * base % mod);
            base = (long long)((__int128)base * base % mod);
            exp >>= 1;
        }
        return result;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        const long long MOD = 1000000007LL;

        // If multiplier is 1, values never change.
        if (multiplier == 1) {
            return nums;
        }

        long long m = multiplier;
        long long maxA = *max_element(nums.begin(), nums.end());

        // R = smallest integer such that m^R >= maxA.
        // After R+1 multiplications applied to ANY single starting value (>=1),
        // that value must exceed maxA, which forces every other (still original)
        // element to be selected first. This bounds how "unbalanced" the picks
        // can get before the process settles into a stable round-robin pattern.
        long long R = 0;
        {
            long long cur = 1;
            while (cur < maxA) {
                cur *= m;
                R++;
            }
        }

        // Directly simulate the "transient" phase with a min-heap.
        long long T1 = min((long long)k, (long long)n * (R + 1));

        vector<long long> modVal(n);   // value mod 1e9+7, for the final answer
        vector<__int128> trueVal(n);   // exact value, safe because exponents stay small here

        for (int i = 0; i < n; i++) {
            modVal[i] = nums[i] % MOD;
            trueVal[i] = (__int128)nums[i];
        }

        // Min-heap of indices, ordered by exact current value (ties by smaller index).
        auto cmp = [&](int a, int b) {
            if (trueVal[a] != trueVal[b]) return trueVal[a] > trueVal[b];
            return a > b;
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < n; i++) pq.push(i);

        for (long long step = 0; step < T1; step++) {
            int idx = pq.top();
            pq.pop();
            modVal[idx] = (modVal[idx] * m) % MOD;
            trueVal[idx] = trueVal[idx] * m;
            pq.push(idx);
        }

        long long remaining = (long long)k - T1;
        if (remaining > 0) {
            // Once the transient phase is over, the process is in an exact
            // round-robin cycle of period n: each element gets multiplied
            // exactly once per block of n operations, always in the SAME
            // relative order (since scaling all values by the same factor m
            // preserves their relative order). So:
            //   - every element gets `fullRounds` more multiplications
            //   - the `extra` elements that are smallest (in the stable order)
            //     get exactly one additional multiplication.
            long long fullRounds = remaining / n;
            long long extraCount = remaining % n;

            // Determine the stable order using the exact values as they stand
            // right now (end of transient, before applying fullRounds) --
            // this order is preserved under any uniform scaling.
            vector<int> order(n);
            iota(order.begin(), order.end(), 0);
            sort(order.begin(), order.end(), [&](int a, int b) {
                if (trueVal[a] != trueVal[b]) return trueVal[a] < trueVal[b];
                return a < b;
            });

            if (fullRounds > 0) {
                long long mPowFull = modpow(m, fullRounds, MOD);
                for (int i = 0; i < n; i++) {
                    modVal[i] = (modVal[i] * mPowFull) % MOD;
                }
            }

            for (long long i = 0; i < extraCount; i++) {
                int idx = order[i];
                modVal[idx] = (modVal[idx] * m) % MOD;
            }
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++) res[i] = (int)modVal[i];
        return res;
    }
};