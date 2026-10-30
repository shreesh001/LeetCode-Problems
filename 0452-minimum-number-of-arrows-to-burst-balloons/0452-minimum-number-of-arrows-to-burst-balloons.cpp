class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();

        sort(points.begin(),points.end());

        int ans=1;

        int start=points[0][0];
        int end=points[0][1];
        for (int i=0;i<n;i++){
            int curr_s=points[i][0];
            int curr_e=points[i][1];
            start=max(start,curr_s);
            end=min(end,curr_e);

            if (start>end){
                ans++;
                start=curr_s;
                end=curr_e;
            }
        }

        return ans;
    }
};