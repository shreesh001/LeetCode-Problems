class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int res=0;

        for (int i=0;i<m;i++){

            int col_conn=0;
            int pref=0;
            for (int j=0;j<n;j++){

                if (grid[i][j]==0) continue;

                pref+=grid[i][j];
                if (pref>1) continue;

                for (int k=0;k<m;k++){
                    if (grid[k][j]==1 && k!=i){
                        col_conn=1;
                        break;
                    }
                }
            }
            if (pref>1) res+=pref;
            else if (col_conn>0) res+=1;
        }

        return res;
    }
};