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
