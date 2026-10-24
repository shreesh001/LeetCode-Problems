class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        vector<int> Month_days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int A_arrive_Month = stoi(arriveAlice.substr(0, 2));
        int B_arrive_Month = stoi(arriveBob.substr(0, 2));

        int A_leave_Month = stoi(leaveAlice.substr(0, 2));
        int B_leave_Month = stoi(leaveBob.substr(0, 2));

        int A_arrive_date = stoi(arriveAlice.substr(3, 2));
        int B_arrive_date = stoi(arriveBob.substr(3, 2));

        int A_leave_date = stoi(leaveAlice.substr(3, 2));
        int B_leave_date = stoi(leaveBob.substr(3, 2));

        int start = max(A_arrive_Month, B_arrive_Month);
        int end = min(A_leave_Month, B_leave_Month);

        if (start > end) {
            return 0;
        }

        int startday = 0, endday = 0;

        if (start == A_arrive_Month && start == B_arrive_Month) {
            startday = max(A_arrive_date, B_arrive_date);
        } else if (start == A_arrive_Month) {
            startday = A_arrive_date;
        } else {
            startday = B_arrive_date;
        }

        if (end == A_leave_Month && end == B_leave_Month) {
            endday = min(A_leave_date, B_leave_date);
        } else if (end == A_leave_Month) {
            endday = A_leave_date;
        } else {
            endday = B_leave_date;
        }

        if (start == end) {
            if (endday<startday){
                return 0;
            }
            else{
                return endday-startday+1;
            }
        }

        int days=Month_days[start]-startday+1+endday;
        for (int i=start+1;i<end;i++){
            days+=Month_days[i];
        }
        return days;

    }
};