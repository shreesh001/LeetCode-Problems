class Solution {
public:

    int maximumLength(vector<int>& nums) {

        unordered_map<int,int>freq;
        for (auto num:nums){
            freq[num]++;
        }

        vector<int>new_nums;
        for (auto [num,count]:freq){
            if (num==1) continue;
            new_nums.push_back(num);
        }
        sort(new_nums.begin(),new_nums.end());

        int max_sz=0;
        int n=new_nums.size();
        for (int i=n-1;i>=0;i--){
            int len=1;
            int num=new_nums[i];
            int prev=sqrt(num);
            while( (prev*prev)==num && freq[prev]>1){
                len+=2;
                num=prev;
                prev=sqrt(num);
            }
            max_sz=max(max_sz,len);
        }
        if (freq.find(1)!=freq.end()){
            if (freq[1]%2==0) freq[1]-=1;
            max_sz=max(max_sz,freq[1]);
        }
        return max_sz;
    }
};