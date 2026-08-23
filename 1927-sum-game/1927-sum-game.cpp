class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        double res=0.0;
        for (int i=0;i<n/2;i++){
            if (num[i]=='?'){
                res+=4.5;
            }
            else res+=(num[i]-'0');
        }
        for (int i=n/2;i<n;i++){
            if (num[i]=='?') res-=4.5;
            else res-=(num[i]-'0');
        }
        if (res!=0.0) return true;
        return false;
    }
};