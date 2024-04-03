class Solution {
public:
  map<int, vector<int>> mp;
    void levelOrder(TreeNode* root, int level){
        if(root == NULL) return;
        if(mp.find(level) != mp.end()){
            mp[level].push_back(root->val);
        }
        else mp[level] = {root->val};
        levelOrder(root->left, level+1);
        levelOrder(root->right, level+1);
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        levelOrder(root, 0);
        int n = mp.size();
        vector<vector<int>> res(n);
        for(auto it = mp.begin(); it != mp.end(); it++){
            res[n-1] = it->second;
            n--;
        }
        return res;
    }
};
