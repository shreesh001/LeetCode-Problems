class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10]={0};
        int res=0;

        for (auto d:digits){
            freq[d]++;
        }

        for (int i=1;i<10;i++){
            for (int j=0;j<10;j++){
                for (int k=0;k<9;k+=2){
                    if (freq[i]>0 && (i==j)<freq[j] && (j==k)+(i==k)<freq[k]){
                        res++;
                    }
                }
            }
        }
        return res;
    }
};