class Solution {

public:
    using ll=long long;
    int N;
    int solve(int step,vector<int>& costs){
        if (step>N){
            return 1e9;
        }
        if (step==N){
            return 0;
        }

        int step1=1+costs[step]+solve(step+1,costs);
        int step2=4+ ( step+1<N ? costs[step+1]:0) +solve(step+2,costs);
        int step3=9+ ( step+2<N ? costs[step+2]:0) +solve(step+3,costs);

        return min({step1,step2,step3});
    }
    int climbStairs(int n, vector<int>& costs) {
        N=n;
        ll state1=0;
        ll state2=1e9;
        ll state3=1e9;

        for (int step=n-1;step>=0;step--){
            int step1=1+costs[step]+state1;
            int step2=4+ ( step+1<N ? costs[step+1]:0) +state2;
            int step3=9+ ( step+2<N ? costs[step+2]:0) +state3;

            int currstate=min({step1,step2,step3});

            state3=state2;
            state2=state1;
            state1=currstate;
        }
        return state1;
    }
};