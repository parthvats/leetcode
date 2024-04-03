class Solution {
public:
    ListNode* mid(ListNode*& start, ListNode*& end){
        ListNode* slow = start;
        ListNode* fast = start;
        while(fast!=end && fast->next!=end){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    TreeNode* toBST(ListNode*& start, ListNode*& end){
        if(start==end) return NULL;
        ListNode* m = mid(start, end);

        TreeNode* root = new TreeNode(m->val);
        root->left = toBST(start, m);
        root->right = toBST(m->next, end);
        return root;
    }


    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* tail = NULL;
        return toBST(head, tail);
    }
};
