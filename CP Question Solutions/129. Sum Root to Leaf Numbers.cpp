class Solution {
private: 
    int res = 0;
public:
    void sum(TreeNode* root, string str){
        if(root == NULL) return;
        str += to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            res += stoi(str);
            return;
        }
        sum(root->left, str);
        sum(root->right, str);
    }
    int sumNumbers(TreeNode* root) {
        sum(root, "");
        return res;
    }
};
