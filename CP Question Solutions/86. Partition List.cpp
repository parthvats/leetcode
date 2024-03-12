class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* temp = new ListNode();
        ListNode* less = temp;
        int val = 0;

        while(head){
            if(head->val<x){
                while(head && head->val<x){
                    temp->next = new ListNode(head->val);
                    temp = temp->next;
                    head = head->next;
                }
                prev->next = head;
                prev = head;
                head = head?head->next:head;
            }
            else {
                prev = head;
                head = head->next;
            }
        }
        temp->next = dummy->next;
        return less->next;
    }
};
