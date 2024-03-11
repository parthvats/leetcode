class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        int len = 0;
        ListNode* temp = head;
        ListNode* res;
        ListNode* slow = head;
        ListNode* fast = head;
        while(temp){
            temp = temp->next;
            len++;
        }
        k = k%len;
        if(k==0) return head;

        for(int i=0; i<k; i++){
            fast = fast->next;
        }

        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }

        res = slow->next;
        slow->next = NULL;
        fast->next = head;
        return res;

    }
};
