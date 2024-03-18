class Solution {
public:
    int res = 0;
    void depth(TreeNode* root, int count){
        if(root==NULL) return ;
        count++;
        res = max(res, count);
        depth(root->left, count);
        depth(root->right, count);

    }
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        res = 1;
        depth(root->left, 1);
        depth(root->right, 1);
        return res;
    }
};
