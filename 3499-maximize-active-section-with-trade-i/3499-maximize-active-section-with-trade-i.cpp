class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        int cnt1=0;
        for (auto ch:s){
            if (ch=='1') cnt1++;
        }
        int max_active=cnt1;
        int l=0;
        int r=0;
        int phase=0;
        bool b1=false,b2=false,b3=false;
        while(r<n){
            while(r<n && s[r]=='0'){
                r++;
                b1=true;
            } 
            int rep1=0;
            while(r<n && s[r]=='1') {
                r++;
                rep1++;
                b2=true;
            }
            while(r<n && s[r]=='0') {
                r++;
                b3=true;
            }
            if (b1 && b2 && b3) max_active=max(max_active,r-l+cnt1-rep1);

            while(l<n && s[l]=='0') l++;
            while(l<n && s[l]=='1') l++;
            b1=true;
            b2=false;
            b3=false;
        }
        return max_active;
    }
};