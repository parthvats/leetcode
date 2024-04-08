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

//Reverse Level Order Traversal
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;

        while(!q.empty()){
            int n  = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* top = q.front();
                if(i == 0) res.push_back(top->val);
                if(top->right != NULL) q.push(top->right);
                if(top->left != NULL) q.push(top->left);
                q.pop();
            }
        }
        return res;
    }
};
