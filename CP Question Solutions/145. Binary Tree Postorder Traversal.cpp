class Solution {
public:
    void postTraversal(TreeNode* root, vector<int>& res){
        if(root == NULL) return;
        postTraversal(root->left, res);
        postTraversal(root->right, res);
        res.push_back(root->val);
        
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postTraversal(root, res);
        return res;
    }
};
