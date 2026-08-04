class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int cnt1=0,cnt0=0;
        int n=s.size();
        vector<int>pref(n,0);
        pref[0]= (s[0]=='1')?1:0;
        if (s[0]=='1') cnt1++;
        else cnt0++;
        for (int i=1;i<n;i++){
            if (s[i]=='0') cnt0++;
            else cnt1++;

            pref[i]=pref[i-1]+((s[i]=='1') ? 1:0);
        }

        cout<<cnt0<<" "<<cnt1;
        
        vector<bool>ans;
        for (int i=0;i<strs.size();i++){
            int c0=0,c1=0;
            for (int j=0;j<n;j++){
                char ch=strs[i][j];
                if (ch=='0') c0++;
                else if (ch=='1') c1++;
            }
            
            int diff1=cnt1-c1;
            int diff0=cnt0-c0;
            for (auto &ch:strs[i]){
                if (ch=='?'){
                    if (diff0>0){
                        ch='0';
                        diff0--;
                    }
                    else{
                        ch='1';
                    }
                }
            }
            c1=0;
            for (int j=0;j<n;j++){
                if (strs[i][j]=='1') c1++;
                if (c1>pref[j]){
                    c1=n;
                    break;
                }
            }
            if (c0>cnt0 || c1>cnt1){
                ans.push_back(false);
                continue;
            }
            ans.push_back(true);
        }
        return ans;
    }
};