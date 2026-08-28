class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        if (n == 1) {
            return s > target ? s : "";
        }
        
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;
        
        int odd = 0;
        char oddch = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) {
                odd++;
                oddch = 'a' + i;
            }
            cnt[i] /= 2;
        }
        
        if (odd > 1) return "";
        
        string build = "";
        int i = 0;
        int half_len = n / 2;
        
        // Step 1: Greedily match the prefix of target's first half
        while (i < half_len && cnt[target[i] - 'a'] > 0) {
            build += target[i];
            cnt[target[i] - 'a']--;
            i++;
        }
        
        // Step 2: Check if exact match of first half naturally yields a valid palindrome
        if (i == half_len) {
            string part2 = build;
            reverse(part2.begin(), part2.end());
            string full_pal = build + (odd ? string(1, oddch) : "") + part2;
            
            if (full_pal > target) {
                return full_pal;
            }
        }
        
        if (i < half_len) {
            int ch = target[i] - 'a';
            for (int k = ch + 1; k < 26; k++) {
                if (cnt[k] > 0) {
                    string temp_build = build + (char)('a' + k);
                    vector<int> temp_cnt = cnt;
                    temp_cnt[k]--;
                    
                    for (int c = 0; c < 26; c++) {
                        while (temp_cnt[c] > 0) {
                            temp_build += (char)('a' + c);
                            temp_cnt[c]--;
                        }
                    }
                    
                    string part2 = temp_build;
                    reverse(part2.begin(), part2.end());
                    return temp_build + (odd ? string(1, oddch) : "") + part2;
                }
            }
        }
        
        // Step 4: Backtrack. If we couldn't branch off at 'i', we must step backwards (i - 1 down to 0)
        for (int j = i - 1; j >= 0; j--) {
            int ch = target[j] - 'a';
            cnt[ch]++; // Release the previously matched character back into our available pool
            
            // Look for a strictly greater character to replace target[j]
            for (int k = ch + 1; k < 26; k++) {
                if (cnt[k] > 0) {
                    string temp_build = build.substr(0, j) + (char)('a' + k);
                    vector<int> temp_cnt = cnt;
                    temp_cnt[k]--;
                    
                    // Fill the rest with the smallest possible available characters
                    for (int c = 0; c < 26; c++) {
                        while (temp_cnt[c] > 0) {
                            temp_build += (char)('a' + c);
                            temp_cnt[c]--;
                        }
                    }
                    
                    string part2 = temp_build;
                    reverse(part2.begin(), part2.end());
                    return temp_build + (odd ? string(1, oddch) : "") + part2;
                }
            }
        }
        
        // If we exhausted all options, no valid string exists
        return "";
    }
};