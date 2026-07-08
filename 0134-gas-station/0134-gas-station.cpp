class Solution {
public:
// by using the difference array logic to check whether the solution exist or not 
// then use the kandane algo to find the starting index of the of the gas station
// very much intutive approach 
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int total_sum=0;
        int Subarray_sum=0;
        int start_ind_of_subarray=0;
        for (int i=0;i<n;i++){
            int diff=gas[i]-cost[i];
            total_sum+=diff;
            Subarray_sum+=diff;
            if (Subarray_sum<0) {
                Subarray_sum=0;
                start_ind_of_subarray=i+1;
            } 
        }
        if (total_sum<0) return -1;
        return start_ind_of_subarray;
    }
};