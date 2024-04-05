class BSTIterator {
private:
    TreeNode* temp;
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root) {
        temp = root;
        s.push(temp);
        while(temp->left != NULL){
            temp = temp->left;
            s.push(temp);
        }
    }
    
    int next() {
        TreeNode* k = s.top();
        s.pop();
        int res = k->val;
        if(k->right != NULL){
            k = k->right;
            s.push(k);
            while(k->left != NULL){
                k = k->left;
                s.push(k);
            }
        }
        return res;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};
