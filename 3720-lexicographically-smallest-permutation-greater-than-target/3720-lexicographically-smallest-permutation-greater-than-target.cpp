class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n=s.size();

        if (n==1){
            if (s[0]>target[0]) return s;
            else return "";
        }
        vector<int>cnt(26,0);

        for (int i=0;i<n;i++){
            cnt[s[i]-'a']++;
        }

        string build="";
        for (int i=0;i<n;i++){
            int ch=target[i]-'a';
            if (cnt[ch]>0){
                build+=target[i];
                cnt[ch]--;
            }
            else{
                bool flag=false;
                for (int j=ch+1;j<26;j++){
                    if (cnt[j]>0) {
                        flag=true;
                        build+=('a'+j);
                        cnt[j]--;
                        break;
                    }
                }

                for (int k=0;k<26;k++){
                    while(cnt[k]>0) {
                        build+=('a'+k);
                        cnt[k]--;
                    }
                }
                
                if (flag==true) return build;
            }
        }
        vector<int>count(26,0);
        string original=build;
        if (build<=target){
            vector<int>cnt(26,0);
            count[build[n-1]-'a']++;
            cnt[build[n-1]-'a']++;
            for (int i=n-2;i>=0;i--){
                int ch=build[i]-'a';
                count[ch]++;
                cnt[ch]++;
                int flag=false;
                for (int j=ch+1;j<26;j++){
                    if (cnt[j]>0){
                        build[i]='a'+j;
                        cnt[j]--;
                        flag=true;
                        break;
                    }
                }
                if (flag==true){
                    int ind=i+1;
                    for (int k=0;k<26;k++){
                        while(cnt[k]>0){
                            build[ind]='a'+k;
                            ind++;
                            cnt[k]--;
                        }
                    }
                }
                if (build>target) return build;
                build=original;
                cnt=count;
            }
        }
        return "";
    }
};