class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int n=s.size();
    int maxlen=0;
    int l=0;
    int r=0;
    map<char,int> mpp;
    while(r<n){
        if (mpp.find(s[r])!=mpp.end()){
            if (l<=mpp[s[r]]){
                l=mpp[s[r]]+1;
            }
        }
        mpp[s[r]]=r;
        maxlen=max(maxlen,r-l+1);
        r++;
    }
    return maxlen;
    }
};