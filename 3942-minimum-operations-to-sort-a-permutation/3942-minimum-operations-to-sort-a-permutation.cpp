class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        if (n==1) return 0;
        vector<int>ind;
        for (int i=1;i<n-1;i++){
            if (nums[i]>nums[i-1] && nums[i]>nums[i+1] ){
                ind.push_back(i);
            }
        }
        
        if (ind.size()>1) return -1;
        
        if (ind.size()==0){
            if (nums[0]==n-1 && (nums[1]==0 || nums[n-1]==0)){
                return 1;
            }
            else if (nums[n-1]==n-1 && (nums[0]==0 || nums[n-2]==0)){
                if (nums[0]==0) return 0;
                if (nums[n-2]==0) return 2;
            }else return -1;
        }

        if (nums[ind[0]]!=n-1) return -1;
        
        if (nums[ind[0]-1]!=0 && nums[ind[0]+1]!=0) return -1;
        int miniop=n;
        if (nums[ind[0]-1]==0){
            miniop=min(ind[0]+1,miniop);
            miniop=min(miniop,1+(n-1-ind[0]+1));
        }
        
        if (nums[ind[0]+1]==0){
            miniop=min(ind[0]+1,miniop);
            miniop=min(miniop,1+(n-1-ind[0])+1);
        }
        return miniop;
    }
};