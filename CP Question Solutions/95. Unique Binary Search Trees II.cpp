class Solution {
public:
    map<vector<int>, vector<TreeNode*>> mp;

    vector<TreeNode*> recurse(int start, int end){
        if(start > end) return {NULL};
        if(mp.find({start,end}) != mp.end()) {
            return mp[{start, end}];
        }
        vector<TreeNode*> temp1, temp2, res;
        TreeNode* root;

        for(int i = start; i <end+1; i++){
            temp1 = recurse(start, i-1);
            temp2 = recurse(i+1, end);
            int p = temp1.size();
            int q = temp2.size();
            for(int j = 0; j < p; j++){
                for(int k = 0; k < q; k++){
                    root = new TreeNode(i);
                    root->left = temp1[j];
                    root->right = temp2[k];
                    res.push_back(root);
                }
            }
        }
        mp[{start, end}]  = res;
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return recurse(1,n);
    }

    
};
