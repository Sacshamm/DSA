class Solution {
public:
  
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        int lh = maxDepth(root -> left);
        int rh = maxDepth(root -> right);
        int ans = max(lh,rh)+1;// recursively adding node 1 by 1

        return ans;
    }
};
