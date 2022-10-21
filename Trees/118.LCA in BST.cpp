class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     if (root == NULL || root == p || root == q) {
    //         return root;
    //     }
    //     TreeNode* left = lowestCommonAncestor(root->left, p, q);
    //     TreeNode* right = lowestCommonAncestor(root->right, p, q);

    //     //result
    //     if(left == NULL) {
    //         return right;
    //     }
    //     else if(right == NULL) {
    //         return left;
    //     }
    //     else { //both left and right are not null, we found our result
    //         return root;
    //     }
    // }
 
     // by taking advantage of BST wherever a node splits that is the lca

     //if both p and q lies on left they should be smaller than root
        if ((root -> val > p -> val) && (root -> val > q -> val)) {
            return lowestCommonAncestor(root -> left, p, q);//keep on returning root->left
        }
     //if both p and q lies on right they should be greater than root
        if ((root -> val < p -> val) && (root -> val < q -> val)) {
            return lowestCommonAncestor(root -> right, p, q);//keep on returning root->right
        }
    //if at any point the p and q splits i.e; p or q == root ya fir p<root and q>root.... that is the LCA and return that node.
        return root;
    }
    
};
