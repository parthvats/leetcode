class Solution {
public:
    bool BOOL = false;
    void sum(TreeNode* root, int target, int currSum){
        if(root == NULL) return;
        currSum += root->val;
        if(root->left == NULL && root->right == NULL && currSum == target){
            BOOL = true;
            return;
        }
        sum(root->left, target, currSum);
        sum(root->right, target, currSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        sum(root, targetSum, 0);
        return BOOL;
    }
};
