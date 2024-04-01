class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);
        q2.push(root);
        int count = 0;

        while(!q1.empty()){
            int n = q1.size();
            vector<int> temp;
            for(int i = 0; i < n; i++){
                TreeNode* node = q1.front();
                TreeNode* t = q2.front();
                temp.push_back(node->val);
                if(count%2 != 0){
                    if(t->left != NULL) q1.push(t->left);
                    if(t->right != NULL) q1.push(t->right);

                    if(node->right != NULL) q2.push(node->right);
                    if(node->left != NULL) q2.push(node->left);
                }
                else{
                    if(t->right != NULL) q1.push(t->right);
                    if(t->left != NULL) q1.push(t->left);

                    if(node->left != NULL) q2.push(node->left);
                    if(node->right != NULL) q2.push(node->right);
                }
                
                q1.pop();
                q2.pop();
            }
            res.push_back(temp);
            count++;
        }
        return res;
    }
};
