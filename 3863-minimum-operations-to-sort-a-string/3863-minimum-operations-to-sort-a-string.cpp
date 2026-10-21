class Solution {
public:
    int minOperations(string s) {
        string s2=s;
        sort(s2.begin(),s2.end());
        if (s2==s) return 0;
        int n=s.size();
        if (n==2) return -1;
        char minichar=s[0];
        int indmini=0;
        char maxichar=s[0];
        int indmaxi=0;
        for (int i=1;i<n;i++){
            if (s[i]<minichar){
                minichar=s[i];
                indmini=i;
            }
            if (s[i]>=maxichar){
                maxichar=s[i];
                indmaxi=i;
            }
        }

        if (indmini==0 || indmaxi==n-1){
            return 1;
        }
        else if (indmini==n-1 && indmaxi==0){
            return 3;
        }
        return 2;
    }
};