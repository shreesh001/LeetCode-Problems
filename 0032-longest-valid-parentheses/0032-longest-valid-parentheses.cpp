class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();

        stack<int>st;
        
        vector<int>dp(n,0);

        for (int i=0;i<n;i++){
            if (s[i]=='(') {
                st.push(i);
            }

            else if (!st.empty() && s[st.top()]=='(' && s[i]==')') {
                dp[st.top()]=1;
                dp[i]=1;
                st.pop();
            }

        }

        int maxlen=0;
        int len=0;
        int i=0;
        
        while(i<n){
            while(i<n && dp[i]==0){
                i++;
            }
            while(i<n && dp[i]==1){
                len++;
                i++;
            }
            maxlen=max(maxlen,len);
            len=0;
        }

        return maxlen;
    }
};