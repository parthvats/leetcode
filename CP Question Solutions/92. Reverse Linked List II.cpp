class Solution {
public:
    ListNode* reverse(ListNode* head, int cnt){
        int count = 0;
        ListNode* front = head;
        ListNode* temp;
        ListNode* prev = NULL;

        while(count!=cnt){
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
            count++;
        }

        front->next = head;
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int count = 1;
        ListNode* res = head;
        ListNode* prev = NULL;

        while(head){
            if(count==left){
                if(prev){
                    prev->next = reverse(head, right-left+1);
                    return res;
                }
                else{
                    return reverse(head, right-left+1);
                }
            }
            else{
                prev = head;
                head = head->next;
            }
            count++;
        }
        return res;
    }
};
