class Solution {
public:
    bool BOOL = true;
    int height(TreeNode* root, int count){
        if(root == NULL){
            return count;
        }
        count++;
        int left = height(root->left, count);
        int right = height(root->right, count);
        BOOL = BOOL && abs(right-left)<=1;
        return max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int temp = height(root,0);
        return BOOL;
    }
};
