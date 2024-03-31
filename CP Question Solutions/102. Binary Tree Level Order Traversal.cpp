class Solution {
public:
    map<int, vector<int>> mp;

    void lvlOrder(TreeNode* root, int level){
        if(root == NULL) return;
        if(mp.find(level) == mp.end()){
            mp[level] = {root->val};
        }
        else{
            mp[level].push_back(root->val);
        }
        lvlOrder(root->left, level+1);
        lvlOrder(root->right, level+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        lvlOrder(root, 0);

        vector<vector<int>> res;
        for(auto it = mp.begin(); it!=mp.end(); it++){
            res.push_back(it->second);
        }
        return res;
    }
};
