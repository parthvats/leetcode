class Solution {
public:
    int total = 0;
    void sum(TreeNode* root, char c){
        if(root == NULL) return;
        if(c == 'l' && root->left == NULL && root->right == NULL){
            total+=root->val;
            return;
        }
        sum(root->left,'l');
        sum(root->right,'r');

    }

    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        sum(root->left,'l');
        sum(root->right,'r');
        return total;
    }
};
