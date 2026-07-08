class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        long long mod=1e9+7;
        int n=s.size();
        vector<long long>prefsum(n,0);
        vector<long long>prefnum(n,0);
        vector<long long>prefdigit(n,0);

        vector<long long>pow10(n+1,0);
        long long val=1;
        pow10[0]=val;
        for (int i=1;i<=n;i++){
            val=(val*10)%mod;
            pow10[i]=val;
        }

        long long sum=0;
        long long num=0;
        long long dig=0;
        for (int i=0;i<n;i++){
            sum=(sum+(s[i]-'0'))%mod;
            prefsum[i]=sum;

            if (s[i]!='0') num=((num*10)%mod+(s[i]-'0'))%mod;
            prefnum[i]=num;

            if (s[i]!='0') dig+=1;
            prefdigit[i]=dig;
        }
    
        vector<int>ans;
        for (auto &q:queries){
            int l=q[0];
            int r=q[1];
            
            long long sum=prefsum[r]-(l-1>=0 ? prefsum[l-1]:0);
            long long k=prefdigit[r]-(l-1>=0 ? prefdigit[l-1]:0);
            long long multipler=pow10[k];

            long long number=(prefnum[r]-((l-1>=0 ? prefnum[l-1]:0)*multipler)%mod+mod)%mod;

            long long res=(sum*number)%mod;
            ans.push_back(res);
        }
        return ans;

    }
};