class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode();
        ListNode* res = temp;
        ListNode* prev;

        int carry = 0;
        int sum;

        while(l1 || l2){
            sum = (l1?l1->val:0) + (l2?l2->val:0) + carry;
            temp->val = sum%10;
            prev = temp;
            temp->next = new ListNode();
            temp = temp->next;
            if(sum >= 10) {
                carry = 1;
            }
            else carry = 0;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(carry==1) temp->val = 1;
        else prev->next = NULL;
        return res;
    }
};
