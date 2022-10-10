class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
       
       if(root == p || root == q) return root;//if it is equal then return root
       
       TreeNode*leftans = lowestCommonAncestor(root->left , p , q );
       TreeNode*rightans = lowestCommonAncestor(root->right , p , q );
       
       if(leftans!= NULL && rightans!= NULL) return root;//if both are not null it means left and right subtree must have returned a node... which means it is a common node btween p & q
       
       else if(leftans!=NULL && rightans==NULL) return leftans;//if left matches with either p or q it is not null
       
       else if(leftans==NULL && rightans!=NULL) return rightans;//vice versa
       
       else return NULL;//if does'nt match with p or q then its NULL
    }
};
