class Solution {
public:
    int minChanges(string s) {
        int n=s.size();
        int moves=0;
        for (int i=0;i<n;i+=2){
            moves+=((s[i]-'0')^(s[i+1]-'0'));
        }
        return moves;
    }
};