class Solution {
public:
    long long ans(long long srt,long long ind,long long diff){
        long long res=srt+((ind-1)*diff);
        return res;
    }
    long long maximumValue(int n, int s, int m) {
        if (n==1) return s;
        long long diff=m-1;
        long long srt=s;
        long long ind=(n+1)/2;
        long long res=0;
        if (n%2==0){
            srt+=m;
            res=ans(srt,ind,diff);
        }
        else{
            res=ans(srt,ind,diff);
            res+=1;
        }
        return res;
    }
};