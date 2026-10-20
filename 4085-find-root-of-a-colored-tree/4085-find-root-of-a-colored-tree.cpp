class Solution {
public:
    int colorofnode(int &node,string &colors){
        if (colors[node]=='R') return 0;
        if (colors[node]=='B') return 1;
        return 2;
    }
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n=colors.size();

        vector<int>indegree(n,0),outdegree(n,0);

        for (auto &ed:edges){
            int u=ed[0];
            int v=ed[1];
            int cu=colorofnode(u,colors);
            int cv=colorofnode(v,colors);

            if (cv-cu==0){
                return -1;
            }
            else{
                if (cu-cv==-1 || cu-cv==2){
                    outdegree[u]++;
                    indegree[v]++;
                }
                else if (cu-cv==1 || cu-cv==-2){
                    outdegree[v]++;
                    indegree[u]++;
                }
                else return -1;
            }
        }

        int root=-1;
        for (int i=0;i<n;i++){
            if (indegree[i]==0){
                if (outdegree[i]<=2){
                    if (root==-1) root=i;
                    else return -1;
                }
            }
        }
        return root;

    }
};