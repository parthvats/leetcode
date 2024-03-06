class Solution {
public:
    int num = 0;
    void dec_num(ListNode* head, int&count){
        if(!head) return ;
        dec_num(head->next, count);
        if(head->val) num+= pow(2,count);
        count++;
    }

    int getDecimalValue(ListNode* head) {
        int count = 0;
        dec_num(head, count);
        return num;
    }
};
