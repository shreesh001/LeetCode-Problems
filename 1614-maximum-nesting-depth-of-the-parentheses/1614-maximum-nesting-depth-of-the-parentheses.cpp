class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int cnt=0;
        int depth=0;
        for (int i=0;i<n;i++){
            if (s[i]=='('){
                depth++;
                cnt=max(cnt,depth);
            }
            else if (s[i]==')'){
                depth--;
            }
            else{
                continue;
            }
        }
        return cnt;
    }
};