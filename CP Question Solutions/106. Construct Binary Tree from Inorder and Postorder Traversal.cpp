class Solution {
public:
    int index;
    TreeNode* connect(vector<int>& inorder, vector<int>& postorder, int start, int end, map<int, int>& mp){
        if(start>end) return NULL;
        TreeNode* root = new TreeNode(postorder[index]);
        int p_idx = mp[root->val];
        index--;
        root->right = connect(inorder, postorder, p_idx+1, end, mp);
        root->left = connect(inorder, postorder, start, p_idx-1, mp);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[inorder[i]] = i;
        }
        index = n-1;
        return connect(inorder, postorder, 0, n-1, mp);
    }
};
