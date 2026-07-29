class Solution {
public:
    long long limit=1e6;
    long long nCr(long long n,long long r){
        if (r<0 || r>n) return 0;
        r=min(r,n-r);
        if (r==0) return 1;
        
        long long res=1;
        for (int i=1;i<=r;i++){
            res=res*(n-r+i)/i;
            if (res>limit) return limit+1;
        }
        return res;
    }
    long long countWays(long long len,vector<int>&count){
        long long ans=1;
        for (int cnt:count){
            if (cnt==0) continue;
            long long res=nCr(len,cnt);
            ans=ans*res;
            if (ans>limit) return limit+1;
            len-=cnt;
        }
        return ans;
    }
    string smallestPalindrome(string s, int k) {
        int n=s.size();
        vector<int>count(26,0);
        for (auto ch:s){
            count[ch-'a']++;
        }
        char odd_ch=0;
        for (int i=0;i<26;i++){
            if (count[i]%2==1){
                odd_ch='a'+i;
                count[i]--;
            }
            count[i]/=2;
        }

        if (countWays(n/2,count)<k) return "";

        string left="";
        for (int i=0;i<n/2;i++){
            long long len=(n/2)-(i+1);

            for (int ch=0;ch<26;ch++){
                if (count[ch]==0) continue;
                count[ch]--;
                long long ways=countWays(len,count);
                if (ways>=k){
                    left+=char('a'+ch);
                    break;
                }
                k-=ways;
                count[ch]++;
            }
        }

        string right=left;
        reverse(right.begin(),right.end());
        if (odd_ch){
            left+=odd_ch;
        }
        string ans=left+right;
        return ans;
    }
};