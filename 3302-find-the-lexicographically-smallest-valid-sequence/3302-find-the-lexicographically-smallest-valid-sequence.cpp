class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<int>matching(n,0);

        int j=m-1;
        for (int i=n-1;i>=0;i--){
            if (j>=0 && word1[i]==word2[j]){
                matching[i]=1;
                j--;
            }
            if (i+1<n) matching[i]+=matching[i+1];
        }

        vector<int>seq;
        j=0;
        bool change=false;
        for (int i=0;i<n;i++){
            if (word1[i]!=word2[j]){
                if (change==true) continue;
                else{
                    if (j<m && i+1<n && matching[i+1]>=m-1-j){
                        change=true;
                        seq.push_back(i);
                        j++;
                    }
                    else continue;
                }
            }
            else{
                seq.push_back(i);
                j++;
            }
        }
        if (j<m) return {};
        return seq;
    }
};