class Solution {
public:
    string digitSum(string s, int k) {
        int n=s.size();

        while(n>k){
            string str="";
            int sum=0;
            for (int i=0;i<n;i++){
                sum+=(s[i]-'0');
                if (i%k==k-1){
                    str+=to_string(sum);
                    sum=0;
                }
            }
            if (sum>=0 && n%k!=0){
                str+=to_string(sum);
                sum=0;
            }
            s=str;
            n=s.size();
        }
        return s;
    }
};