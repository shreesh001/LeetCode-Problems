class Solution {
public:
    bool checkString(string s) {
        int n=s.size();
        int flagb=0;
        for (int i=0;i<n;i++){
            if (s[i]=='b'){
                flagb=1;
            }

            if (s[i]=='a' && flagb==1) return false;
        }
        return true;
    }
};