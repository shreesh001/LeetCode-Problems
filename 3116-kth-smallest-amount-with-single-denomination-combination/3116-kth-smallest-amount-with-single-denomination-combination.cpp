class Solution {
public:
    using ll=long long;
    long long count_number(ll mid,vector<int>& coins){
        int n=coins.size();
        ll count=0;
        for (ll exp=1;exp<=(1<<n)-1;exp++){
            ll order=0;
            ll lcm=0;
            for (ll i=0;i<n;i++){
                if (exp&(1<<i)){
                    order++;
                    if (lcm==0) lcm=coins[i];
                    else{
                        lcm=(lcm*coins[i])/gcd(lcm,coins[i]);
                    }
                }
            }
            if (order&1) count+=(mid/lcm);
            else count-=(mid/lcm);
        }
        return count;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        ll res=-1;
        ll low=1;
        ll high=k*1ll*(*max_element(coins.begin(),coins.end()));

        while(low<=high){
            ll mid=(low+high)/2;
            if (count_number(mid,coins)>=k){
                res=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return res;
    }
};