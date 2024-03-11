class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* temp;
        ListNode* res = head->next;
        ListNode* prev = NULL;

        while(head->next){
            temp = head->next->next;
            if(prev) prev->next = head->next;
            head->next->next = head;
            head->next = temp;
            prev = head;
            head = head->next;
            if(!head) return res;
            
        }
        return res;
    }
};
