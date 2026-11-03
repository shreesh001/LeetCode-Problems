class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();

        vector<int>pt(k,0);

        int rangediff=1e9;

        int mini_val=-1e5;
        int maxi_val=1e5;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        priority_queue<int>pq2;

        for (int lst=0;lst<k;lst++){
            int ind=pt[lst];
            int val=nums[lst][ind];
            pq.push({val,lst});
            pq2.push(val);
        }

        while(true){

            int mini=pq.top().first;
            int list_no=pq.top().second;

            pq.pop();

            int maxi=pq2.top();

            int diff=maxi-mini;
            if (diff<rangediff){
                rangediff=diff;
                mini_val=mini;
                maxi_val=maxi;
            }

            int len=nums[list_no].size();
            if (pt[list_no]+1<len){
                pt[list_no]++;
                int val=nums[list_no][pt[list_no]];
                pq.push({val,list_no});
                pq2.push(val);
            }
            else break;
        }

        return {mini_val,maxi_val};
    }
};