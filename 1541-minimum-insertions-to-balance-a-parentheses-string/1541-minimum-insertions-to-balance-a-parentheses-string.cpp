class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        stack<char>st;
        int extra=0;
        for (int i=0;i<n;i++){
            if (s[i]=='('){
                st.push('(');
            }
            else if (s[i]==')'){
                if (st.empty()){
                    if (i<n && s[i+1]==')'){
                        extra+=1;
                        i++;
                    }
                    else extra+=2;
                }
                else{
                    st.pop();
                    if (i<n && s[i+1]==')'){
                        i++;
                    }
                    else extra+=1;
                }
            }
        }
        return (2*st.size())+extra;
    }
};