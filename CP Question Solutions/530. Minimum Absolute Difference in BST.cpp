class Solution {
public:
    int res = INT_MAX;
    int prev = -1;

    int getMinimumDifference(TreeNode* root) {
        if(root == NULL) return res;
        getMinimumDifference(root->left);
        if(prev != -1){
            res = min(res, ((root->val)-prev));

        }
        prev = root->val;
        getMinimumDifference(root->right);
        return res;
    }
};
