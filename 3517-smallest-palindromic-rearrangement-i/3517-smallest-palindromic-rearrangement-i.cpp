class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>cnt(26,0);
        for (auto ch:s){
            cnt[ch-'a']++;
        }
        string ans="";
        char oddch;
        for (int i=0;i<26;i++){
            char ch='a'+i;
            int count=cnt[i];
            if (count%2==1) oddch=ch;
            for (int i=1;i<=count/2;i++){
                ans+=ch;
            }
        }
        string revans=ans;
        reverse(revans.begin(),revans.end());
        if (oddch){
            ans+=oddch;
        }
        return ans+revans;
    }
};