class Solution {
public:
    int merge(vector<int>& nums,int low,int mid,int high){
        vector<int>temp;
        int left=low;
        int right=mid+1;
        int cnt=0;
        while(left<=mid){
            while(right<=high && 1ll*nums[left]>2*1ll*nums[right]) right++;
            cnt+=(right-mid-1);
            left++;
        }
        left=low;
        right=mid+1;
        while(left<=mid && right<=high){
            if (nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }
        left=low;
        for (int i=0;i<temp.size();i++){
            nums[left]=temp[i];
            left++;
        }

        return cnt;
    }
    int mergesort(vector<int>& nums,int low,int high){
        int cnt=0;
        if (low>=high) return cnt;
        int mid=(low+high)/2;
        cnt+=mergesort(nums,low,mid);
        cnt+=mergesort(nums,mid+1,high);
        cnt+=merge(nums,low,mid,high);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        return mergesort(nums,low,high);
    }
};