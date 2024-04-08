class Solution {
public:
    set<int> s;
    void recursion(TreeNode* root){
        if(root == NULL) return;
        s.insert(root->val);
        recursion(root->left);
        recursion(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        recursion(root);
        int i = 1;
        for(auto it = s.begin(); it != s.end(); it++){
            if(i == k) return *it;
            i++;
        }
        return 0;
    }
};
