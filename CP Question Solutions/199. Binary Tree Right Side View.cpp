class Solution {
private:
    vector<int> right;
public:
    void rightView(TreeNode* root, int level){
        if(root == NULL) return;
        if(level >= right.size())right.push_back(root->val);
        rightView(root->right, level+1);
        rightView(root->left, level+1);

    }
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return right;
        rightView(root, 0);
        return right;
        
    }
};
