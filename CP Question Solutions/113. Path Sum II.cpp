class Solution {
public:
    vector<vector<int>> res;
    void Sum(TreeNode* root, int targetSum, int sumSoFar, vector<int>& temp ){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            sumSoFar += root->val;
            if(sumSoFar == targetSum){
                temp.push_back(root->val);
                res.push_back(temp);
                temp.pop_back();
            }
            return;
        }
        sumSoFar += root->val;
        temp.push_back(root->val);
        Sum(root->left, targetSum, sumSoFar, temp);
        Sum(root->right, targetSum, sumSoFar, temp);
        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        Sum(root, targetSum, 0, temp);
        return res;
    }
};
