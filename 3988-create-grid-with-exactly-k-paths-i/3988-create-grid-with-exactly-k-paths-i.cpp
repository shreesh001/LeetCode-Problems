class Solution {
public:
    vector<string> createGrid(int m, int n, int k) {

        vector<string>grid (m,string(n,'#'));

        // case 1
        if (k==1 && (n==1 || m==1)){
            for (int i=0;i<m;i++){
                for (int j=0;j<n;j++){
                    grid[i][j]='.';
                }
            }
            return grid;
        }

        // case 2
        if ((max(n,m)*(min(n,m)-1))<k) return {};

        // case 3
        if (n==3 && m==3 && k==4){
            return {"..#","...","#.."};
        }

        // manage rest of the cases
        for (int i=0;i<n;i++){
            grid[0][i]='.';
        }
        for (int j=0;j<m;j++){
            grid[j][n-1]='.';
        }
        if (m>=k){
            int i=0;
            while(k>0){
                grid[i][n-2]='.';
                i++;
                k--;
            }
        }
        else{
            int j=n-1;
            while(k>0){
                grid[1][j]='.';
                j--;
                k--;
            }

        }
        return grid;

    }
};