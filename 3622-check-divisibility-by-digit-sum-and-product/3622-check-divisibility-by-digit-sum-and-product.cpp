class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int prod=1;
        int num=n;
        while(num>0){
            int dig=num%10;
            sum+=dig;
            prod*=dig;
            num=num/10;
        }
        return ((n%(sum+prod))==0);
    }
};