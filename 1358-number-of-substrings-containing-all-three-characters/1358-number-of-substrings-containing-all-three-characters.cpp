class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int a=-1,b=-1,c=-1;
        int cnt=0;
        for (int i=0;i<n;i++){
            if (s[i]=='a'){
                a=i;
            }
            else if (s[i]=='b'){
                b=i;
            }
            else{
                c=i;
            }
            cnt+=(min(a,min(b,c))+1);
        }
        return cnt;
    }
};