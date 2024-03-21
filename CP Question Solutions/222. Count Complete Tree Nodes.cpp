class Solution {
public:
    int count_ll = 0;
    int lev = -1;
    int end = 0;
    void count(TreeNode* root, int level){
        if(end == 0){
            if(root == NULL) return;
            if(root->left == NULL && root->right == NULL){
                lev = lev==-1?level:lev;
            }
            level++;
            if(level == lev && root->right == NULL) {
                end = 1;
                count_ll += root->left!=NULL?1:0;
                return;
            }
            if(level>lev && root->left == NULL && root->right == NULL) count_ll++;
            count(root->left, level);
            count(root->right, level);
        } 

    }

    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        count(root, 0);
        int cnt = (1<<lev)-1 + count_ll;
        return cnt;
    }
};
