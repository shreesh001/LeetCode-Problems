class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long totcost=cost1+cost2;
        long long ans=0;
        ans=(1ll*need1*cost1)+(1ll*need2*cost2);
        int req=min(need1,need2);
        ans=min(ans,1ll*req*costBoth+(1ll*cost1*(need1-req))+(1ll*cost2*(need2-req)));
        req=max(need1,need2);
        ans=min(ans,1ll*req*costBoth);
        return ans;
    }
};