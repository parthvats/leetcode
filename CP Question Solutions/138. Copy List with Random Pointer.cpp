class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;

        Node* dummy = head;
        map<Node*, Node*> map;

        while(head){
            map[head] = new Node(head->val);
            head = head->next;
        }

        for(auto it=map.begin(); it!=map.end(); it++){
            it->second->next = it->first->next?map[it->first->next]:NULL;
            it->second->random = it->first->random?map[it->first->random]:NULL;
        }

        return map[dummy];

    }
};



O(1) space complexity solution below:

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node* cpy1 = head;
        Node* cpy2 = head;
        Node* temp;

        while(head){
            temp = head->next;
            head->next = new Node(head->val);
            head->next->next = temp;
            head = temp;
        }

        while(cpy1){
            cpy1->next->random = cpy1->random?cpy1->random->next:NULL;
            cpy1 = cpy1->next->next;
        }

        Node* res = new Node(0);
        Node* temp1 = res;

        while(cpy2){
            res->next = cpy2->next;
            res = res->next;
            cpy2->next = cpy2->next->next;
            cpy2 = cpy2->next;
        }

        return temp1->next;
    }
};
