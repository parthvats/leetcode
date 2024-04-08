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

//Better solution as the tree is Binary Search Tree
class Solution {
private:
    int count;
    int res;
public:
    void kSmallest(TreeNode* root){
        if(root == NULL) return;
        if(count == 0) return;
        kSmallest(root->left);
        count--;
        if(count == 0){
            res = root->val;
            return;
        }
        kSmallest(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        count = k;
        kSmallest(root);
        return res;
    }
};
