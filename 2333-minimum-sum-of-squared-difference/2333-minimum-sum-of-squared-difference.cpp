class Solution {
public:
    bool ispossible(int cnt,int mid,int moves){
        if ((1ll*cnt*1ll*mid)>1ll*moves){
            return false;
        }
        return true;
    }
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {

        int n=nums1.size();
        int moves=k1+k2;

        map<int,int>mpp;
        for (int i=0;i<n;i++){
            int diff=abs(nums1[i]-nums2[i]);
            mpp[diff]+=1;
        }

        priority_queue<pair<int,int>>pq;

        for (auto it:mpp){
            pq.push({it.first,it.second});
        }

        while(moves>0){
            int el=pq.top().first;
            int cnt=pq.top().second;
            if (el==0) break;
            if (cnt>moves) break;

            pq.pop();
            int diff=el;
            if (!pq.empty()){
                diff=el-pq.top().first;
            }

            int low=1;
            int high=diff;
            int new_diff=0;
            while(low<=high){
                int mid=(low+high)/2;
                if (ispossible(cnt,mid,moves)){
                    new_diff=mid;
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }

            if (new_diff==0){
                pq.push({el,cnt});
                break;
            }
            else if (new_diff==diff){
                moves-=(diff*cnt);
                int curr_top_cnt=0;
                if (!pq.empty()){
                    curr_top_cnt=pq.top().second;
                    pq.pop();
                }
                pq.push({el-diff,curr_top_cnt+cnt});
            }
            else{
                moves-=(cnt*new_diff);
                int newel=el-new_diff;
                pq.push({newel,cnt});
            }

        }

        if (moves>0){
            int el=pq.top().first;
            int cnt=pq.top().second;
            if (el!=0){
                pq.pop();
                pq.push({el-1,moves});
                pq.push({el,cnt-moves});
            }
            
        }

        long long val=0;
        while(!pq.empty()){
            long long el=pq.top().first;
            long long cnt=pq.top().second;
            cout<<el<<" "<<cnt<<"\n";
            val+=cnt*(el*el);
            pq.pop();
        }
        return val;


    }
};