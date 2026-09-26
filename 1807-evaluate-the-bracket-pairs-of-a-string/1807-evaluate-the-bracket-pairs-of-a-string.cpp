class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string res="";
        int n=s.size();

        unordered_map<string,string>mpp;
        for (auto &vec:knowledge){
            mpp[vec[0]]=vec[1];
        }

        for (int i=0;i<n;i++){

            if (s[i]=='('){
                i++;
                string key="";
                while(i<n && s[i]!=')'){
                    key+=s[i];
                    i++;
                }
                if (mpp.find(key)!=mpp.end()) res+=mpp[key];
                else res+='?';
            }
            else{
                res+=s[i];
            }
        }
        return res;

    }
};