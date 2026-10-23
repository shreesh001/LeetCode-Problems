class Solution {
public:
    int minSelection(vector<vector<int>>& availableIntervals, vector<vector<int>>& targetIntervals) {

        //merging the target intervals
        sort(targetIntervals.begin(),targetIntervals.end());

        vector<vector<int>>tar;

        for (auto &t:targetIntervals){
            if (tar.empty() || tar.back()[1]<t[0]){
                tar.push_back(t);
            }
            else{
                tar.back()[1]=max(tar.back()[1],t[1]);
            }
        }

        // sort available intervals
        sort(availableIntervals.begin(),availableIntervals.end());

        int i=0;
        int n=availableIntervals.size();

        int covered=-1;
        int cnt=0;
        for (auto t:tar){
            int l=t[0];
            int r=t[1];

            if (covered<l){
                while(i<n && availableIntervals[i][0]<=l){
                    covered=max(covered,availableIntervals[i][1]);
                    i++;
                }
                if (covered<l) return -1;
                cnt++;
            }

            while (covered<r){
                int next=covered;
                while(i<n && availableIntervals[i][0]<=covered){
                    next=max(next,availableIntervals[i][1]);
                    i++;
                }
                if (covered==next) return -1;
                cnt++;
                covered=next;
            }

            if (covered>=r) continue;
        }

        return cnt;

    }
};