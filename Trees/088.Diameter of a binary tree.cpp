class Solution {
public:
    int height(TreeNode*node){
        if(node==0) return 0;
        int left = height(node->left);
        int right = height(node->right);
        int ans = max(left,right)+1;

        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
       int leftd = diameterOfBinaryTree(root->left);
       int rightd = diameterOfBinaryTree(root->right);
       int heightFromRoot = height(root->left)+height(root->right);
       
       int maxi = max(heightFromRoot, max(leftd,rightd));

       return maxi;
    }
};
