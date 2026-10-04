class Solution {
public:
    int dp[101][201];
    int solve(int ind,int sum,string& s){
        int n=s.size();
        if (sum<0) return false;
        if (ind==n-1){
            if (s[ind]==')' || s[ind]=='*'){
                if (s[ind]=='*' && sum==0) return true;
                if (sum==1) return true;
                return false;
            }
            return false;
        } 
        if (dp[ind][sum]!=-1) return dp[ind][sum];
        bool res=false;
        if (s[ind]=='('){
            res=res||solve(ind+1,sum+1,s);
        }
        else if (s[ind]==')'){
            res=res||solve(ind+1,sum-1,s);
        }
        else{
            res=res||solve(ind+1,sum+1,s)||solve(ind+1,sum-1,s)||solve(ind+1,sum,s);
        }
        return dp[ind][sum]=res;
    }
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s);
    }
};