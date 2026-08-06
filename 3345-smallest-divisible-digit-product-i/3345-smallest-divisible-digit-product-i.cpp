class Solution {
public:
    int smallestNumber(int n, int t) {
        int num=n;
        while(true){
            int prod=1;
            while(num>0){
                int dig=num%10;
                num=num/10;
                prod*=dig;
            }
            if (prod%t==0) return n;
            n++;
            num=n;
        }
        return 0;
    }
};