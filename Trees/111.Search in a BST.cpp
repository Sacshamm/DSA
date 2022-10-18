class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return root;
            if(val<root->val){
                root=searchBST(root->left,val);
            } else if(val>root->val){
                root=searchBST(root->right,val);
            }
            
        return root;

        // while(root != nullptr && val != root->val){
        //     if(val < root->val) root = root->left;
        //     else root = root->right;
        // }
        // return root;
    }
};
