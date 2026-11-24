class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        for (int i=0;i<n;i++){
            int prod=1;
            int g=nums[i];
            int l=nums[i];
            for (int j=i;j<n;j++){

                prod*=nums[j];
                if (prod>1e5) break;
                g=gcd(g,nums[j]);
                l=lcm(l,nums[j]);

                if (prod==g*l){
                    maxi=max(maxi,j-i+1);
                }

            }
        }
        return maxi;
    }

};