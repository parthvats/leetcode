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
