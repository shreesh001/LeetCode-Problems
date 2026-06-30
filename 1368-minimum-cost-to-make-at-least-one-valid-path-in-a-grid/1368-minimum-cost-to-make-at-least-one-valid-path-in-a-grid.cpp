class Solution {
public:
    int minCost(vector<vector<int>>& grid) {

        int m=grid.size();
        int n=grid[0].size();

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};

        vector<vector<int>>cost(m,vector<int>(n,n*m));

        pq.push({0,0,0});
        cost[0][0]=0;

        while(!pq.empty()){
            auto vec=pq.top();
            int move=vec[0];
            int x=vec[1];
            int y=vec[2];
            pq.pop();
            if (x==m-1 && y==n-1) return move;
            
            // if it goes in the particular given direction as well as any direction
            for (int i=0;i<4;i++){
                int nx=x+dir[i][0];
                int ny=y+dir[i][1];
                if (nx>=0 && nx<m && ny>=0 && ny<n){
                    if (i==grid[x][y]-1){
                        if (cost[nx][ny]>move){
                            cost[nx][ny]=move;
                            pq.push({move,nx,ny});
                        }
                    }
                    else{
                        if (cost[nx][ny]>move+1){
                            cost[nx][ny]=move+1;
                            pq.push({move+1,nx,ny});
                        }
                    }
                }
            }
        }
        return 0;
    }
};