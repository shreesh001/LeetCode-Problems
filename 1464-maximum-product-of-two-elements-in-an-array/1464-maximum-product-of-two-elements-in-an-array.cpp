class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int num1=INT_MIN;
        int num2=INT_MIN;
        for (auto num:nums){
            if (num>num1){
                num2=num1;
                num1=num;
            } 
            else if (num>num2){
                num2=num;
            }
        }
        return ((num1-1)*(num2-1));
    }
};