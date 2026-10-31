class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();

        stack<int>st;
        int first=n+2;
        int last=n+1;
        int maxi=0;
        for (int i=0;i<n;i++){
            
            if (!st.empty() && st.top()>nums[i]){
                last=i;
                int maxi=st.top();
                while(!st.empty() && st.top()>nums[i]){
                    st.pop();
                }
                first=min((int)st.size(),first);
                st.push(nums[i]);
                st.push(maxi);
            }

            else st.push(nums[i]);
            
        }

        return last-first+1;
    }
};