/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head==nullptr || head->next==nullptr || head->next->next==nullptr) return {-1,-1};
        ListNode* prev=head;
        ListNode* curr=head->next;
        int ind=1;
        vector<int>pos;
        int minima=1e5;
        while(curr->next!=nullptr){
            ListNode *next=curr->next;
            if ((curr->val>prev->val && curr->val>next->val) || (curr->val<prev->val && curr->val<next->val)){
                if (pos.size()>0){
                    minima=min(minima,ind-pos.back());
                }
                pos.push_back(ind);
            }
            prev=curr;
            curr=next;
            ind++;
        }
        if (pos.size()<=1){
            return {-1,-1};
        }

        int maxima=pos[pos.size()-1]-pos[0];
        return {minima,maxima};
    }
};