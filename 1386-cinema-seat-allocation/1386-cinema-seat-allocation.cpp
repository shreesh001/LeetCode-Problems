class Solution {
public:
    bool check_1_exist(unordered_set<int>&booked){
        bool s1=true,s2=true,s3=true;
        for (int i=2;i<=5;i++){
            if (booked.find(i)!=booked.end()) s1=false;
        }
        if (s1) return true;

        for (int i=4;i<=7;i++){
            if (booked.find(i)!=booked.end()) s2=false;
        }
        if (s2) return true;

        for (int i=6;i<=9;i++){
            if (booked.find(i)!=booked.end()) s3=false;
        }
        if (s3) return true;

        return false;
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m=reservedSeats.size();
        sort(reservedSeats.begin(),reservedSeats.end());
        // total_groups
        int res=2*n;
        int l=0;
        int r=0;
        while(r<m){
            unordered_set<int>booked;
            while(r<m && reservedSeats[r][0]==reservedSeats[l][0]){
                if (reservedSeats[r][1]!=1 && reservedSeats[r][1]!=10){
                    booked.insert(reservedSeats[r][1]);
                } 
                r++;
            }
            if (booked.size()!=0){
                bool exist=check_1_exist(booked);
                if (exist) res-=1;
                else res-=2;
            }
            l=r;
            booked.clear();
        }
        return res;
    }
};