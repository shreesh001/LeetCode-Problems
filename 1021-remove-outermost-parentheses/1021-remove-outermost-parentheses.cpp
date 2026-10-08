class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        if (n==1){
            return "";
        }
        stack<char> st;
        string ans="";
        for (int i=0;i<n;i++){
            if (st.empty() && s[i]=='('){
                st.push(s[i]);
                continue;
            }
            else if (st.size()==1 && s[i]==')'){
                st.pop();
                continue;
            }

            if (s[i]=='('){
                st.push(s[i]);
                ans+=s[i];
            }
            else if (s[i]==')'){
                st.pop();
                ans+=s[i];
            }    
        }
        return ans;
    }
};