class Solution {
public:
    long long beautifulSubstrings(string s, int k) {
        long long n=s.size();
        long long v=0,c=0;
        long long res=0;

        unordered_map<long long,unordered_map<long long,long long>>mpp;
        mpp[0][0]=1;
        
        for (int i=0;i<n;i++){
            char ch=s[i];
            if (ch=='a'|| ch=='e'|| ch=='i' || ch=='o' || ch=='u') v++;
            else c++;
            int diff=v-c;
            
            for (auto &[cnt_of_v,count]:mpp[diff]){
                if ((v%k-cnt_of_v)*(v%k-cnt_of_v)%k==0) res+=count;
            }
            mpp[diff][v%k]++;
        }
        return res;
    }
};