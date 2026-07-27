class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int srt_sum=start[0]+start[1];
        int end_sum=target[0]+target[1];
        if (srt_sum%2==0 && end_sum%2==0){
            return true;
        }
        else if (srt_sum%2!=0 && end_sum%2!=0){
            return true;
        }
        return false;
    }
};