class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if (rec1==rec2) return true;

        int bottomleft=max(rec1[0],rec2[0]);
        int bottomright=max(rec1[1],rec2[1]);
        int upperleft=min(rec1[2],rec2[2]);
        int upperight=min(rec1[3],rec2[3]);

        if (bottomleft>=upperleft) return false;
        if (bottomright>=upperight) return false;
        
        return true;
    }
};