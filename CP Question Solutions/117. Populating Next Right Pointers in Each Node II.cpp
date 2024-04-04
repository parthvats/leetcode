class Solution {
public:
    map<int, vector<Node*>> mp;

    void nextConnect(Node* root, int level){
        if(root == NULL) return;
        if(mp.find(level) != mp.end()){
            int n = mp[level].size();
            mp[level].push_back(root);
            mp[level][n-1]->next = mp[level][n];
        }
        else{
            mp[level] = {root};
        }
        nextConnect(root->left, level+1);
        nextConnect(root->right, level+1);
    }

    Node* connect(Node* root) {
        nextConnect(root, 0);
        return root;
    }
};

// iterateive solution

class Solution {
public:
    Node* connect(Node* root) {
        Node* curr  = root;

        while(curr != NULL){
            Node* head = NULL;
            Node* tail = NULL;
            while(curr!=NULL){
                if(curr->left != NULL){
                    if(head == NULL && tail == NULL){ // also we can write as  if(head == NULL)
                        head = curr->left;
                        tail = curr->left;
                    }
                    else{
                        tail->next = curr->left;
                        tail = tail->next;
                    }
                }
                if(curr->right != NULL){
                    if(head == NULL && tail == NULL){// also we can write as  if(head == NULL)
                        head = curr->right;
                        tail = curr->right;
                    }
                    else{
                        tail->next = curr->right;
                        tail = tail->next;
                    }
                }
                curr = curr->next;
            }
            curr = head;
        }
        return root;
    }
};
