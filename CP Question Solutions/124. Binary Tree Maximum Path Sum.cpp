class Solution {
private:
    int res = INT_MIN;
public:
    int maxSum(TreeNode* root){
        if(root == NULL) return 0;
        int left_max = max(maxSum(root->left), 0);
        int right_max = max(maxSum(root->right), 0);
        int total_path_sum = left_max + right_max + root->val;
        res = max(res, total_path_sum);
        return max(left_max, right_max) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return res;
    }
};
