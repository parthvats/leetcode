class Solution {
public:
    void inorder(TreeNode* root, vector<int>& res){
        if(root==NULL) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        inorder(root, res);
        return res;
    }
};


// Morris Traversal

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;

        TreeNode* curr = root;

        while(curr != NULL){
            if(curr->left == NULL){
                res.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* temp = curr->left;
                while(temp->right != NULL && temp->right != curr){
                    temp = temp->right;
                }

                if(temp->right == NULL){
                    temp->right = curr;
                    curr = curr->left;
                }
                else if(temp->right == curr){
                    temp->right = NULL;
                    res.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return res;
    }
};
