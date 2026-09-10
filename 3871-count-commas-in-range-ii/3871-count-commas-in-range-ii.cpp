class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0;
        int k=1;
        while(true){
            long long srt=pow(10,3*k);
            if (srt>n) break;
            long long end=min(n,(long long)pow(10,3*(k+1))-1);
            long long cnt=end-srt+1;
            ans+=cnt*k;
            k++;
        }
        return ans;
    }
};