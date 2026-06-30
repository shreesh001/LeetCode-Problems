class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {

        int m=grid.size();
        int n=grid[0].size();
        if (grid[0][1]>1 && grid[1][0]>1) return -1;
        vector<vector<int>>vis(m,vector<int>(n,0));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};

        pq.push({0,0,0});
        vis[0][0]=1;
        while(!pq.empty()){
            auto vec=pq.top();
            pq.pop();
            int time=vec[0];
            int x=vec[1];
            int y=vec[2];
            if (x==m-1 && y==n-1) return time;

            for (auto d:dir){
                int nx=x+d[0];
                int ny=y+d[1];
                if (nx>=0 && ny>=0 && nx<m && ny<n && !vis[nx][ny]){
                    vis[nx][ny]=1;
                    if (grid[nx][ny]<=time+1){
                        pq.push({time+1,nx,ny});
                    }
                    else{
                        int time_diff=grid[nx][ny]-time;
                        if (time_diff%2==0){
                            pq.push({grid[nx][ny]+1,nx,ny});
                        }
                        else{
                            pq.push({grid[nx][ny],nx,ny});
                        }
                    }
                }
            }
        }
        return -1;
    }
};