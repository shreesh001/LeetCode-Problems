class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for (int i=1;i<=9;i++){
            int dig=i;
            int num=0;
            while(num<low && dig<10){
                num=(num*10)+dig;
                dig++;
            }
            while(num>=low && num<=high && dig<=10){
                ans.push_back(num);
                num=(num*10)+dig;
                dig++;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};