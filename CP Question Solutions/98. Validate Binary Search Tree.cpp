class Solution {
public:
    long long int mx = LONG_LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        bool b1 = isValidBST(root->left);
        if(!b1) return false;
        if(root->val <=mx ) return false;
        else mx = root->val;
        bool b2 = isValidBST(root->right);
        return b1 && b2;
    }
};
