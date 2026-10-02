class Solution {
public:
    void solve(int op,int cl,vector<string> &ans,string &str,int n){
        if (str.size()==2*n){
            ans.push_back(str);
            return;
        }
        if (op<n){
            str.push_back('(');
            solve(op+1,cl,ans,str,n);
            str.pop_back();
        }
        if (cl<op){
            str.push_back(')');
            solve(op,cl+1,ans,str,n);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n){
        vector<string> ans;
        string str="";
        solve(0,0,ans,str,n);
        return ans;
    }
};