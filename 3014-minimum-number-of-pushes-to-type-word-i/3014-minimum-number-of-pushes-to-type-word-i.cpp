class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        if (n<=8){
            return n;
        }
        if (n<=16){
            return 8+(n-8)*2;
        }
        if (n<=24){
            return 8+16+(n-16)*3;
        }
        if (n<=26){
            return 8+16+24+(n-24)*4;
        }
        return 0;
    }
};