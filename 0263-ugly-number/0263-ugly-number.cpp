class Solution {
public:
    bool isUgly(int n) {
        int num = n;
        if (n <= 0) return false;
        while(num>1){
            while(num%2==0){
                num=num/2;
            }
            while(num%3==0){
                num=num/3;
            }
            while(num%5==0){
                num=num/5;
            }
            if (num>1) return false;
        }
        return true;
    }
};