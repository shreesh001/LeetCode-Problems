class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());

        vector<long long>factors(maxi+1,0);

        // finding freq of factors
        for (int j=0;j<n;j++){
            int num=nums[j];
            for (int i=1;i*i<=num;i++){
                if (num%i==0){
                    factors[i]++;
                    if ((num/i)!=i) factors[num/i]++;
                }
            }
        }

        // finding the pairs
        for (int i=1;i<=maxi;i++){
            long long freq=factors[i];
            if (freq<2){
                factors[i]=0;
                continue;
            }
            factors[i]=(freq*(freq-1))/2;
        }

        //fixing the cnt of pairs

        for (int i=maxi;i>=1;i--){
            for (int j=2*i;j<=maxi;j+=i){
                factors[i]-=factors[j];
            }
        }

        // converting it to prefix sum so that i can find the value at the particular index
        for (int i=1;i<=maxi;i++){
            factors[i]+=factors[i-1];
        }
        
        vector<int>ans;
        for (auto q:queries){
            auto ind=upper_bound(factors.begin(),factors.end(),q)-factors.begin();
            ans.push_back(ind);
        }
        return ans;
    }
};