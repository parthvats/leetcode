class Solution {
public:
    vector<string> vect;
    void path(TreeNode* root, string str){
        if(root == NULL) return;
        str+=to_string(root->val);
        str+="->";
        if(root->left == NULL && root->right == NULL){
            str.erase(str.size()-1);
            str.erase(str.size()-1);
            vect.push_back(str);
            return;
        }
        path(root->left, str);
        path(root->right, str);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL) return {};
        
        path(root, "");
        return vect;
    }
};
