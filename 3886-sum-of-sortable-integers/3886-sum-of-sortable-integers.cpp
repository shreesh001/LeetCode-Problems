class Solution {
public:
    bool checksorting(int ind_min,int d,vector<int>& nums,int min_el,int j){
        int seq_el=min_el;
        for (int k=1;k<d;k++){
            int id=(ind_min+k)%d+(j-1)*d;
            int currel=nums[id];
            if (currel<seq_el){
                return false;
            }
            seq_el=currel;
        }
        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();

        vector<int>divisors;
        
        for (int i=1;i*i<=n;i++){
            if (n%i==0){
                divisors.push_back(i);
                if (i!=(n/i)){
                    divisors.push_back(n/i);
                }
            }
        }

        int sum=0;
        

        for (int i=0;i<divisors.size();i++){
            
            int d=divisors[i];
            int prev_max=0;
            bool flag=true;

            for (int j=1;j<=n/d;j++){

                int max_el=0;
                int min_el=1e5;
                int ind_min=-1;

                for (int k=0;k<d;k++){
                    int ind=((j-1)*d)+k;
                    int el=nums[ind];
                    if (el>=max_el){
                        max_el=el;
                        int left_ind=(ind+1)%d+(j-1)*d;
                        if (nums[left_ind]<=min_el){
                            min_el=nums[left_ind];
                            ind_min=left_ind;
                        }
                    }
                    max_el=max(max_el,el);
                }
                if (min_el<prev_max){
                    flag=false;
                    break;
                }

                flag=checksorting(ind_min,d,nums,min_el,j);
                prev_max=max_el;
                if (flag==false) break;
            }

            if (flag==true){
                sum+=d;
            }
        }
        return sum;
    }
};