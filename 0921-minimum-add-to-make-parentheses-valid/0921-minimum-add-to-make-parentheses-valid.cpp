class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        int moves=0;
        int depth=0;
        for (int i=0;i<n;i++){
            if(s[i]=='(') depth++;
            else if (s[i]==')' && depth==0) moves++;
            else depth--;
        }
        return depth+moves;
    }
};