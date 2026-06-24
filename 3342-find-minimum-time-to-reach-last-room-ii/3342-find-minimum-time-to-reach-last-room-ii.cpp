class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        // we can solve this problem using dijkstra algo 
        // min heap <time,i,j> 
        // normal bfs should be here 
        // i have to also check weather the following thing is under adjacent room time or not 
        int n=moveTime.size();
        int m=moveTime[0].size();

        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>>pq;

        vector<vector<long long>>time(n,vector<long long>(m,LLONG_MAX));
        
        pq.push({0,0,0,0});
        time[0][0]=0;
        while(!pq.empty()){
            auto vec=pq.top();
            pq.pop();
            int curr_time=vec[0];
            int i=vec[1];
            int j=vec[2];
            int time_taken=vec[3]+1;
            if (i==n-1 && j==m-1) return curr_time;

            for (auto d:dir){
                int ni=i+d[0];
                int nj=j+d[1];
                if (ni>=0 && ni<n && nj>=0 && nj<m){
                    if (curr_time>=moveTime[ni][nj]){
                        if (time[ni][nj]>curr_time+time_taken){
                            time[ni][nj]=curr_time+time_taken;
                            pq.push({time[ni][nj],ni,nj,time_taken%2});
                        }
                    }
                    else{
                        if (time[ni][nj]>moveTime[ni][nj]+time_taken){
                            time[ni][nj]=moveTime[ni][nj]+time_taken;
                            pq.push({time[ni][nj],ni,nj,time_taken%2});
                        }
                    }
                }
            }
            
        }
        return 0;
    }
};