class Solution {
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        if(root->left == NULL){
            if(root->right == NULL){
                prev = root;
            }
            else{
                flatten(root->right);
            }
            return;
        }
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = NULL;
        flatten(root->right);
        if(prev != NULL) prev->right = temp;
        flatten(temp);
    }
};

// post order traversal solution
class Solution {
private: TreeNode* prev = NULL;
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};


