class Solution {
public:
    // applying the direct backtracking logic here
    unordered_map<string,int>freq;
    void generatestring(int ind,int open,int close,int sum,string& s,string &curr,vector<string>&res){
        int n=s.size();
        if (sum<0) return;
        if (ind==n){
            if (open==0 && close==0){
                if (freq.count(curr)>0) return;
                res.push_back(curr);
                freq[curr]+=1;
                return;
            }
            return;
        }

        if (s[ind]=='('){
            if (open>0){
                generatestring(ind+1,open-1,close,sum,s,curr,res);
            }
        }

        if (s[ind]==')'){
            if (close>0){
                generatestring(ind+1,open,close-1,sum,s,curr,res);
            }
        }
        curr.push_back(s[ind]);
        int add=0;
        if (s[ind]==')') add=-1;
        else if (s[ind]=='(') add=1;
        generatestring(ind+1,open,close,sum+add,s,curr,res);
        curr.pop_back();
    }
    vector<string> removeInvalidParentheses(string s) {
        int n=s.size();
        int close=0;
        int open=0;
        int cnt=0;
        for (int i=0;i<n;i++){
            if (s[i]=='('){
                cnt++;
            }
            else if (s[i]==')'){
                if (cnt==0){
                    close++;
                }
                else cnt--;
            }
        }
        open=cnt;

        if (open==0 && close==0) return {s};
        if (open+close==n) return {""};
        cout<<open<<" "<<close<<" ";
        vector<string>res;
        string curr="";

        generatestring(0,open,close,0,s,curr,res);

        return res;

    }
};