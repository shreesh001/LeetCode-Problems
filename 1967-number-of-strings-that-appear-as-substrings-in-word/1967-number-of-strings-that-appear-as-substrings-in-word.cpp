class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n=word.size();
        map<string,int>mpp;
        for (int i=0;i<n;i++){
            string s="";
            for (int j=i;j<n;j++){
                s+=word[j];
                mpp[s]++;
            }
        }

        int res=0;
        for (auto str:patterns){
            if (mpp.count(str)>0) res++;
        }
        return res;
    }
};