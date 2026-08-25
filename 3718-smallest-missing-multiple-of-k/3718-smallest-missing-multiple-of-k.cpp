class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st;
        for (auto num:nums){
            st.insert(num);
        }

        int mul=k;
        
        while(st.find(mul)!=st.end()) mul+=k;

        return mul;

    }
};