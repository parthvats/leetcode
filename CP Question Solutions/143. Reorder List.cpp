class Solution {
public:
    int mid;
    ListNode* prev = NULL;
    void rearrange(ListNode*& head, ListNode* tail, int len){
        if(!tail) {
            mid = ((len-1)/2)+1;
            return;
        }
        rearrange(head, tail->next, len+1);
        if(len>=mid){
            if(prev)prev->next = head;
            ListNode* temp = head->next;
            head->next = tail;
            if(len==mid) tail->next = NULL;
            head = temp;
            prev = tail;
        }
    }


    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* temp = head;
        rearrange(head, head, 1);
    }
};
