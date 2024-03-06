class Solution {
public:
    bool check(ListNode*& head, ListNode*& tail){
        if(!tail->next){
            bool var1 = (head->val==tail->val);
            head = head->next;
            return var1;
        }
        if(!check(head, tail->next)) return false;
        bool var2 = (head->val==tail->val);
        head = head->next;
        return var2;
    }

    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        return check(head, head);
    }
};
