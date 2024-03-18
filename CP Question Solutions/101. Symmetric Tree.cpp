class Solution {
public:
    bool mirror(TreeNode* l, TreeNode* r){
        if(l==NULL && r==NULL) return true;
        if((l==NULL && r!=NULL) || (l!=NULL && r==NULL))return false;

        return (l->val==r->val) && mirror(l->left, r->right) && mirror(l->right, r->left);
    }
    bool isSymmetric(TreeNode* root) {
        return mirror(root->left, root->right);
    }
};
