class Solution {
public:
    long long sumAndMultiply(int n) {
        string s=to_string(n);

        long long sum=0;
        string new_num="0";
        for (auto ch:s){
            if (ch!='0') new_num+=ch;
            sum+=(ch-'0');
        }
        long long num=stoll(new_num);
        return (sum*num);
        
    }
};