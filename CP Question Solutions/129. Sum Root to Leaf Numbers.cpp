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

// with using stoi or to_string nethods

class Solution {
private: 
    int res = 0;
public:
    void sum(TreeNode* root, int num){
        if(root == NULL) return;
        num += root->val;
        if(root->left == NULL && root->right == NULL){
            res += num;
            return;
        }
        sum(root->left, num*10);
        sum(root->right, num*10);
    }
    int sumNumbers(TreeNode* root) {
        sum(root, 0);
        return res;
    }
};
