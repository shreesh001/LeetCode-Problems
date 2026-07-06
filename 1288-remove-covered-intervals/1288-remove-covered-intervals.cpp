class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](const auto &vec1,const auto &vec2){
            if (vec1[0]==vec2[0]) return vec1[1]>=vec2[1];
            return vec1[0]<vec2[0];
        });
        int ans=1;
        vector<int>inter=intervals[0];
        for (int i=1;i<n;i++){
            if (inter.back()>=intervals[i][1]) continue;
            else{
                ans++;
                inter=intervals[i];
            }
        }
        return ans;
    }
};