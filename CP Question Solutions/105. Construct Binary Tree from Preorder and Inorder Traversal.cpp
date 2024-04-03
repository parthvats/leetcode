class Solution {
public:
    int index = 0;
    TreeNode* connect(vector<int>& preorder, vector<int>& inorder, int start, int end){
        if(start>end) return NULL;
        TreeNode* root = new TreeNode(preorder[index]);
        int p_idx;
        for(int i = start; i < end; i++){
            if(inorder[i] == preorder[index]){
                p_idx = i;
                break;
            }
        }
        index++;
        root->left = connect(preorder, inorder, start, p_idx-1);
        root->right = connect(preorder, inorder, p_idx+1, end);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return connect(preorder, inorder, 0, preorder.size()-1);
    }
};
