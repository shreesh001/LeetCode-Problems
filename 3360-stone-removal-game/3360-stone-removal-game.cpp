class Solution {
public:
    bool canAliceWin(int n) {
        int rem=10;
        while(n>=rem){
            n-=rem;
            rem--;
        }
        if (rem%2==1) return true;
        return false;
    }
};