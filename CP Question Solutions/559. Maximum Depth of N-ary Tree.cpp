class Solution {
public:
    int res = 0;
    void depth(Node* root, int len){
        int n = (root->children).size();
        if(n == 0){
            res = max(res, len+1);
            return;
        } 
        for(int i = 0; i < n; i++){
            depth(root->children[i], len+1);
        }
        
    }

    int maxDepth(Node* root) {
        if(root == NULL) return 0;
        depth(root, 0);
        return res;
    }
};
