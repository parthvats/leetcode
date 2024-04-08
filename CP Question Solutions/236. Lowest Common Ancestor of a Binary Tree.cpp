//Efficient way
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return root;
        if(p == root || q == root) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left == NULL && right == NULL) return NULL;
        else if(left != NULL && right == NULL) return left;
        else if(left == NULL && right != NULL) return right;
        else return root;
    }
};

//My sol
class Solution {
    vector<TreeNode*> v1;
    vector<TreeNode*> v2;
    bool p_found = false;
    bool q_found = false;
public:
    void LCA(TreeNode* root, TreeNode* p, TreeNode* q, vector<TreeNode*>& temp1, vector<TreeNode*>& temp2){
        if(p_found && q_found) return;
        if(root == NULL) return;
        temp1.push_back(root);
        temp2.push_back(root);
        if(!p_found && p == root){
            v1 = temp1;
            p_found = true;
        } 
        else if(!q_found && q == root){
            v2 = temp2;
            q_found = true;
        } 
        LCA(root->left, p, q, temp1, temp2);
        LCA(root->right, p, q, temp1, temp2);
        temp1.pop_back();
        temp2.pop_back();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> temp1;
        vector<TreeNode*> temp2;
        LCA(root, p, q, temp1, temp2);
        int m = v1.size();
        int n = v2.size();
        int idx = 0;
        int i = 0;
        while(i < m && i < n){
            if(v1[i]!=v2[i]){
                idx = i-1;
                break;
            }
            i++;
        }
        if((i < m && i < n) || (i == m && i == n)) return v1[idx];
        else if(i == m) return p;
        else return q;
    }
};
