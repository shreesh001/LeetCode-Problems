class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        vector<pair<int,int>>vec;

        int n=profits.size();
        for (int i=0;i<n;i++){
            vec.push_back({capital[i],profits[i]});
        }

        sort(vec.begin(),vec.end());

        priority_queue<pair<int,int>>pq;

        int cnt=0;

        int total_capital=w;

        for (int i=0;i<n;i++){

            int cap=vec[i].first;
            int pro=vec[i].second;

            if (cap<=w){
                pq.push({pro,cap});
            }
            else{
                if (!pq.empty() && cnt<k){
                    int p=pq.top().first;
                    int c=pq.top().second;
                    pq.pop();
                    w+=p;
                    total_capital+=p;
                    cnt++;
                    i--;
                }
            }
            cout<<w<<" ";
            
        }

        while(!pq.empty() && cnt<k){
            int p=pq.top().first;
            int c=pq.top().second;
            pq.pop();

            w+=p;
            total_capital+=p;
            cnt++;
        }

        return total_capital;

    }
};