class Solution {
public:
    ListNode* res;
    void mNode(ListNode*& head, ListNode* tail){
        if(tail->next==NULL){
            if(head==tail || head->next==tail) res = tail;
            head = head->next;
            return;
        }
        mNode(head, tail->next);
        if(head==tail || head->next==tail) {
            res = tail;
        }
        head = head->next;

    }

    ListNode* middleNode(ListNode* head) {
        mNode(head, head);
        return res;
    }
};
