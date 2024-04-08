class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == NULL) return {};
        
        queue<TreeNode*> q;
        q.push(root);
        vector<double> res;
        double sum;
        
        while(!q.empty()){
            sum = 0;
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* top = q.front();
                sum += top->val;
                if(top->left != NULL) q.push(top->left);
                if(top->right != NULL) q.push(top->right);
                q.pop();
            }
            double num = sum/n;
            res.push_back(num);
        }
        return res;
    }
};
