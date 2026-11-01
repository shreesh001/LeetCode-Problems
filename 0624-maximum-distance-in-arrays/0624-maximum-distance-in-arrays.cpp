class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n=arrays.size();

        vector<pair<int,int>>vec;
        for (int i=0;i<n;i++){

            int len=arrays[i].size();
            int maxi_val=arrays[i][len-1];

            vec.push_back({maxi_val,i});
        }

        sort(vec.rbegin(),vec.rend());

        int dist=0;
        for (int i=0;i<n;i++){
            int mini=arrays[i][0];
            int maxi=0;
            if (i==vec[0].second){
                maxi=vec[1].first;
            }
            else{
                maxi=vec[0].first;
            }
            dist=max(dist,maxi-mini);
        }

        return dist;
    }
};