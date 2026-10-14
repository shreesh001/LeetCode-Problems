class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (ceil((double)sum/num)>=10) return "";
        string ans;
        if (sum>=1 && sum<=9){
            ans += sum + '0';  
            while ((num-1)>0){
                ans+='0';
                num--;
            } 
            return ans;
        }
        ans="";
        int size=0;
        while(sum>9){
            ans+="9";
            size++;
            sum=sum-9;
        }
        if (sum>0){
            char c=sum+'0';
            ans=ans+c;
            sum=0;
            size++;
        }
        while (size<num){
            ans+='0';
            size++;
        }
        return ans;
    }
};