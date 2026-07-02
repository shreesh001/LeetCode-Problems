class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>cost(m,vector<int>(n,1e9));
        deque<vector<int>>dq;

        vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};

        int cst=0;
        if (grid[0][0]==1) cst=1;
        dq.push_front({cst,0,0});
        cost[0][0]=cst;

        while(!dq.empty()){
            auto vec=dq.front();
            dq.pop_front();
            int cst=vec[0];
            int x=vec[1];
            int y=vec[2];
            if (x==m-1 && y==n-1){
                if (cst<health) return true;
                else return false;
            }
            for (auto d:dir){
                int nx=x+d[0];
                int ny=y+d[1];
                if (nx>=0 && nx<m && ny>=0 && ny<n){
                    if (cost[nx][ny]>cst+grid[nx][ny]){
                        cost[nx][ny]=cst+grid[nx][ny];
                        if (grid[nx][ny]==0){
                            dq.push_front({cost[nx][ny],nx,ny});
                        }
                        else{
                            dq.push_back({cost[nx][ny],nx,ny});
                        }
                    }
                }
            }
        }
        return false;
    }
};