class Solution {
public:
    void preTraversal(TreeNode* root, vector<int>& res){
        if(root == NULL) return;
        res.push_back(root->val);
        preTraversal(root->left, res);
        preTraversal(root->right, res);
        
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preTraversal(root, res);
        return res;
    }
};
