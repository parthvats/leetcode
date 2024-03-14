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

With less Space Complexity 

class Solution {
public:
    void merge(ListNode* A, ListNode* B){
        ListNode* temp;
        while(A && B){
            temp = A->next;
            A->next = B;
            A = temp;
            temp = B->next;
            B->next = A;
            B = temp;
        }
    }

    ListNode* reverse(ListNode* A, ListNode* B){
        if(!A){
            return B;
        }
        ListNode* temp = A->next;
        A->next = B;
        return reverse(temp, A);
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* a = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* rev = reverse(slow->next, NULL);
        slow->next = NULL;

        merge(a, rev);
    }
};
