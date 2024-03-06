class Solution {
public:
    ListNode* recursion(ListNode* A, ListNode* B){
        if(!A) {
            return B;
        }
        ListNode* next = A->next;
        A->next = B;
        return recursion( next, A);
    }
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next) return head;
        return recursion(head, NULL);
    }
};
