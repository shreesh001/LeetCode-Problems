class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        int n=intervals.size();
        int res=0;
        int end=intervals[0][1];
        for (int i=1;i<n;i++){
            int start=intervals[i][0];
            if (start<end){
                res++;
            }
            else{
                end=intervals[i][1];
            }
        }

        int s=intervals[n-1][0];

        int res2=0;
        for (int i=n-2;i>=0;i--){
            int e=intervals[i][1];
            if (e>s){
                res2++;
            }
            else{
                s=intervals[i][0];
            }
        }

        return min(res,res2);
    }
};