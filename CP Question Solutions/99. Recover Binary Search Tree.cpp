class Solution {
public:
    TreeNode* firstEle = NULL;
    TreeNode* secondEle = NULL;
    TreeNode* prevEle = NULL;

    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }

        inorder(root->left);
        if(prevEle != NULL){
            if(firstEle == NULL && prevEle->val >= root->val){
                firstEle = prevEle;
                
            }

            if(firstEle != NULL && prevEle->val >= root->val){
                secondEle = root;
            }
            
        } 
        prevEle = root;    
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        int temp = firstEle->val;
        firstEle->val = secondEle->val;
        secondEle->val = temp;
        
    }
};
