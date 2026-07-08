class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        if (s.size()==0 || words.size()==0) return ans;

        // hashing 
        unordered_map<string,int>mpp;
        for (auto str:words){
            mpp[str]+=1;
        }

        
        // one window size would also be there  len= words[0].size();

        int block_sz=words[0].size();
        int num_words=words.size();
        int n=s.size();

        for (int i=0;i<block_sz;i++){
            int left=i;
            int right=i;
            int blocks=0;
            unordered_map<string,int>window_mpp;
            while(right+block_sz<=n){
                string str=s.substr(right,block_sz);
                right+=block_sz;

                if (mpp.find(str)!=mpp.end()){
                    if (mpp[str]>0){
                        window_mpp[str]++;
                        blocks++;
                    }
                    while(mpp[str]<window_mpp[str]){
                        string left_str=s.substr(left,block_sz);
                        window_mpp[left_str]--;
                        left+=block_sz;
                        blocks--;
                    }
                    if (blocks==num_words) ans.push_back(left);
                }
                else{
                    window_mpp.clear();
                    blocks=0;
                    left=right;
                }
            }
        }
        return ans;

    }
};