class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode();
        ListNode* res = temp;
        ListNode* prev;

        int carry = 0;
        int sum;

        while(l1 && l2){
            sum = l1->val + l2->val + carry;
            temp->val = sum%10;
            prev = temp;
            temp->next = new ListNode();
            temp = temp->next;
            if(sum >= 10) {
                carry = 1;
            }
            else carry = 0;
            l1 = l1->next;
            l2 = l2->next;
        }

        if(!l1 && !l2) {
            if(carry==0)prev->next = NULL;
        }
        else if(!l1){
            while(l2){
                sum = l2->val + carry;
                temp->val = sum%10;
                prev = temp;
                temp->next = new ListNode();
                temp = temp->next;
                if(sum >= 10) {
                    carry = 1;
                }
                else carry = 0;
                l2 = l2->next;
            }
        }
        else if(!l2){
            while(l1){
                sum = l1->val + carry;
                temp->val = sum%10;
                prev = temp;
                temp->next = new ListNode();
                temp = temp->next;
                if(sum >= 10) {
                    carry = 1;
                }
                else carry = 0;
                l1 = l1->next;
            }
        }
        if(carry>0) temp->val = 1;
        else prev->next = NULL;
        return res;
    }
};
