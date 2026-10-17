class Solution {
public:
    int minSwaps(vector<int>& nums) {

        int n=nums.size();

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        unordered_map<int,int>Res_ind;

        for (int i=0;i<n;i++){
            int num=nums[i];

            int sum=0;
            while(num>0){
                int rem=num%10;
                num=num/10;
                sum+=rem;
            }

            pq.push({sum,nums[i]});
        }
        int ind=0;
        while(!pq.empty()){
            int el=pq.top().second;
            pq.pop();
            Res_ind[el]=ind;
            ind++;
        }

        int i=0;
        int swap_cnt=0;
        while(i<n){
            int num=nums[i];
            int final_ind=Res_ind[num];
            if (final_ind==i){
                i++;
                continue;
            }
            swap_cnt++;
            swap(nums[i],nums[final_ind]);
        }

        return swap_cnt;

        

    }
};