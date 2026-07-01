class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
        
        vector<vector<long long>>moves(m,vector<long long>(n,1e9));
        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>>pq;
        pq.push({0,0,0});
        moves[0][0]=0;

        while(!pq.empty()){
            auto vec=pq.top();
            pq.pop();
            int move=vec[0];
            int r=vec[1];
            int c=vec[2];

            if (r==m-1 && c==n-1) return move;

            for (auto d:dir){
                int nr=r+d[0];
                int nc=c+d[1];
                if (nr>=0 && nr<m && nc>=0 && nc<n){
                    if (moves[nr][nc]>move+grid[nr][nc]){
                        moves[nr][nc]=move+grid[nr][nc];
                        pq.push({moves[nr][nc],nr,nc});
                    }
                }
            }
        }
        return 0;
    }
};