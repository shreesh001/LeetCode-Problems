class Solution {
public:
    string countAndSay(int n) {
        if (n==1) return "1";
        string s="1";
        for (int i=2;i<=n;i++){
            int j=0;
            string str="";
            char ch;
            int cnt=0;
            while(j<s.size()){
                if (cnt==0){
                    ch=s[j];
                    cnt++;
                    j++;
                }
                while(j<s.size() && ch==s[j]){
                    cnt++;
                    j++;
                }
                if (ch!=s[j]){
                    str+=(cnt+'0');
                    str+=(ch);
                    cnt=0;
                }
            }
            s=str;
        }
        return s;
    }
};