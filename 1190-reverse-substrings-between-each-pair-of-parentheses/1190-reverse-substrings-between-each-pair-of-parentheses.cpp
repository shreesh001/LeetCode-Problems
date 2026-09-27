class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;

        int n=s.size();
        string res="";
        for (int i=0;i<n;i++){
            if (s[i]==')'){
                string str="";
                while(st.top()!='('){
                    str+=st.top();
                    st.pop();
                }
                st.pop();
                int m=str.size();

                for (int j=0;j<m;j++){
                    st.push(str[j]);
                }
            }
            else st.push(s[i]);
        }

        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};