class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int>ans;

        for (int i=0;i<n;i++){
            int num=nums[i];

            while(!ans.empty() && ans.back()>num && (ans.size()+n-i)>k){
                ans.pop_back();
            }

            if (ans.size()<k) ans.push_back(num);
        }

        return ans;
    }
};