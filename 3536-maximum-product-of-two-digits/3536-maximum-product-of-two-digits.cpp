class Solution {
public:
    int maxProduct(int n) {
        string str=to_string(n);
        sort(str.rbegin(),str.rend());
        return (str[0]-'0')*(str[1]-'0');
    }
};