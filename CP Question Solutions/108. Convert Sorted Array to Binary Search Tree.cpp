class Solution {
public:
    TreeNode* bst(vector<int>& nums, int start, int end){
        if(start > end ) return NULL;
        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = bst(nums, start, mid-1);
        root->right = bst(nums, mid+1, end);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return NULL;
        if(n==1) return new TreeNode(nums[0]);
        int mid = n/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = bst(nums, 0, mid-1);
        root->right = bst(nums, mid+1, n-1);
        return root;
    }
};
