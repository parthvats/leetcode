class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val == val){
            head = head->next;
        }
        if(!head || !head->next) return head;

        ListNode* prev = head;
        ListNode* ans = head;
        
        while(head){
            if(head->val == val){
                prev->next = head->next;
            }
            else prev = head;
            head = head->next;
        }
        return ans;
    }
};
