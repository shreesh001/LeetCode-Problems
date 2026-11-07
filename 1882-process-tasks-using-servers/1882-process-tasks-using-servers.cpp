class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        // priority_queue + ordered_map problem 

        int n=servers.size();
        int m=tasks.size();

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        map<long long,vector<pair<int,int>>>mpp;

        for (int i=0;i<n;i++){
            pq.push({servers[i],i});
        }

        long long time=0;
        vector<int>ans(m,0);

        for (int i=0;i<m;i++){

            time=max(time,(long long)i);
            long long task_time=tasks[i];

            if (mpp.find(time)!=mpp.end()){
                for (auto &p:mpp[time]){
                    pq.push(p);
                }
                mpp.erase(time);
            }

            if (pq.empty()){
                auto it=mpp.begin();
                time=it->first;
                for (auto &p:mpp[time]){
                    pq.push(p);
                }
                mpp.erase(time);
            }

            long long time_comp=task_time+time;
            auto sv=pq.top();
            pq.pop();
            ans[i]=sv.second;
            mpp[time_comp].push_back(sv);
        }

        return ans;
    }
};