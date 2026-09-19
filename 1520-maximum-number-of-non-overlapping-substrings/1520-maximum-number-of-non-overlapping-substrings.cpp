class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();

        vector<int>first(26,-1),last(26,-1);
        vector<int>valid(n,false);
        for (int i=0;i<n;i++){
            if (first[s[i]-'a']==-1){
                first[s[i]-'a']=i;
                valid[i]=true;
            }
            last[s[i]-'a']=i;
        }

        


        for (int c=0;c<26;c++){
            int start=first[c];
            int end=last[c];

            if (start==-1) continue;

            for (int i=start;i<=end;i++){
                int ch=s[i];
                if (first[ch-'a']<start){
                    valid[start]=false;
                    break;
                }
                end=max(last[ch-'a'],end);
                last[c]=end;
            }
        }

        vector<string>res;

        int lastind=n+5;

        for (int i=n-1;i>=0;i--){
            int ch=s[i];
            
            if (!valid[i]) continue;

            int start=first[ch-'a'];
            int end=last[ch-'a'];

            if (end<lastind){
                res.push_back(s.substr(start,end-start+1));
                lastind=start;
            }
        }

        return res;
    }
};