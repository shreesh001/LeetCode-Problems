#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Maximum prime factor bounds deduced from t <= 10^14 limit
const int MAX2 = 60;
const int MAX3 = 40;
vector<vector<string>> best(MAX2 + 1, vector<string>(MAX3 + 1, string(100, '9')));
bool initialized = false;

// Precompute optimal minimal string composition for properties of 2s and 3s
void init() {
    if (initialized) return;
    vector<vector<string>> dp(MAX2 + 1, vector<string>(MAX3 + 1, string(100, '9')));
    dp[0][0] = "";
    
    for (int len = 0; len <= 40; ++len) {
        for (int i = 0; i <= MAX2; ++i) {
            for (int j = 0; j <= MAX3; ++j) {
                if (dp[i][j].length() == len) {
                    for (int d : {2, 3, 4, 6, 8, 9}) {
                        int c2 = (d == 8) ? 3 : (d == 4 ? 2 : (d % 2 == 0 ? 1 : 0));
                        int c3 = (d == 9) ? 2 : (d % 3 == 0 ? 1 : 0);
                        int ni = min(MAX2, i + c2);
                        int nj = min(MAX3, j + c3);
                        string cand = dp[i][j] + (char)('0' + d);
                        sort(cand.begin(), cand.end());
                        if (cand.length() < dp[ni][nj].length() || 
                           (cand.length() == dp[ni][nj].length() && cand < dp[ni][nj])) {
                            dp[ni][nj] = cand;
                        }
                    }
                }
            }
        }
    }
    
    // Accumulate the absolute best answers for "at least" factor reqs
    for(int i = 0; i <= MAX2; ++i){
        for(int j = 0; j <= MAX3; ++j){
            for(int x = i; x <= MAX2; ++x){
                for(int y = j; y <= MAX3; ++y){
                    if (dp[x][y].length() < best[i][j].length() || 
                       (dp[x][y].length() == best[i][j].length() && dp[x][y] < best[i][j])) {
                        best[i][j] = dp[x][y];
                    }
                }
            }
        }
    }
    initialized = true;
}

class Solution {
public:
    string smallestNumber(string num, long long t) {
        init();
        
        long long temp = t;
        int req2 = 0, req3 = 0, req5 = 0, req7 = 0;
        while (temp % 2 == 0) { req2++; temp /= 2; }
        while (temp % 3 == 0) { req3++; temp /= 3; }
        while (temp % 5 == 0) { req5++; temp /= 5; }
        while (temp % 7 == 0) { req7++; temp /= 7; }
        if (temp > 1) return "-1"; // Unfulfillable non-base prime factor present
        
        int L = num.length();
        vector<int> pref2(L + 1, 0), pref3(L + 1, 0), pref5(L + 1, 0), pref7(L + 1, 0);
        int z_idx = L;
        for(int i = 0; i < L; ++i) {
            if (num[i] == '0') {
                z_idx = min(z_idx, i);
            }
            pref2[i+1] = pref2[i]; pref3[i+1] = pref3[i]; 
            pref5[i+1] = pref5[i]; pref7[i+1] = pref7[i];
            
            if (num[i] != '0') {
                int d = num[i] - '0';
                if (d == 8) pref2[i+1] += 3;
                else if (d == 4) pref2[i+1] += 2;
                else if (d % 2 == 0) pref2[i+1] += 1;
                
                if (d == 9) pref3[i+1] += 2;
                else if (d % 3 == 0) pref3[i+1] += 1;
                
                if (d == 5) pref5[i+1] += 1;
                if (d == 7) pref7[i+1] += 1;
            }
        }
        
        // Return baseline match immediately if the exact num perfectly satisfies all conditions
        if (z_idx == L && pref2[L] >= req2 && pref3[L] >= req3 && 
            pref5[L] >= req5 && pref7[L] >= req7) {
            return num;
        }
        
        // Search optimally iterating back-to-front
        for (int i = L - 1; i >= 0; --i) {
            if (i > z_idx) continue;
            int start_d = max(1, num[i] - '0' + 1);
            
            for (int d = start_d; d <= 9; ++d) {
                int c2 = (d == 8) ? 3 : (d == 4 ? 2 : (d % 2 == 0 ? 1 : 0));
                int c3 = (d == 9) ? 2 : (d % 3 == 0 ? 1 : 0);
                int c5 = (d == 5) ? 1 : 0;
                int c7 = (d == 7) ? 1 : 0;
                
                int rem2 = max(0, req2 - pref2[i] - c2);
                int rem3 = max(0, req3 - pref3[i] - c3);
                int rem5 = max(0, req5 - pref5[i] - c5);
                int rem7 = max(0, req7 - pref7[i] - c7);
                
                int req_len = best[rem2][rem3].length() + rem5 + rem7;
                int avail_len = L - 1 - i;
                
                if (req_len <= avail_len) {
                    string ans = num.substr(0, i) + to_string(d);
                    string suff = string(avail_len - req_len, '1') + string(rem5, '5') + 
                                  string(rem7, '7') + best[rem2][rem3];
                    sort(suff.begin(), suff.end());
                    ans += suff;
                    return ans;
                }
            }
        }
        
        // If string structure bounds exceeded string length; construct purely scaled minimal size padding
        int req_len = best[req2][req3].length() + req5 + req7;
        int N = max(L + 1, req_len);
        string ans = string(N - req_len, '1') + string(req5, '5') + string(req7, '7') + best[req2][req3];
        sort(ans.begin(), ans.end());
        return ans;
    }
};