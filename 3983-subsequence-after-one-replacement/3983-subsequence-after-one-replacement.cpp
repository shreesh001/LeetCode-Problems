class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int si=0;  // pointer that does not use the its change character power
        int ssi=0;  // pointer that use the move and chnage the character already
        for (int i=0;i<t.size();i++){
            if (ssi<s.size()){
                if (s[ssi]==t[i]) ssi++;
            }
            if (si<s.size()){
                if (s[si]==t[i]) si++;
                else ssi=max(ssi,si+1);
            }
        }
        if (max(ssi,si)>=s.size()) return true;
        return false;
    }
};