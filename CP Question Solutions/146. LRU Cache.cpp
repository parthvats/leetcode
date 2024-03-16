class LRUCache {
public:
    class Node{
        public:
            int key;
            int val;
            Node* prev;
            Node* next;

            Node(int key, int val){
                this->key = key;
                this->val = val;
                this->prev = NULL;
                this->next = NULL; 
            }
    };

    int cap;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    unordered_map<int, Node*> map;

    void addNode(Node* node){
        Node* temp = head->next;
        
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }

    void delNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    LRUCache(int capacity) {
        this->cap = capacity;
        this->head->next = tail;
        this->tail->prev = head;

    }
    
    int get(int key) {
        if(map.find(key) != map.end()){
            Node* temp = map[key];
            delNode(temp);
            addNode(temp);
            return map[key]->val;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value){
        if(map.find(key) != map.end()){
            delNode(map[key]);
            map.erase(key);
        }
        if(map.size() == cap){
            map.erase(tail->prev->key);
            delNode(tail->prev);
        }
        map[key] = new Node(key, value);
        addNode(map[key]);
    }
};
