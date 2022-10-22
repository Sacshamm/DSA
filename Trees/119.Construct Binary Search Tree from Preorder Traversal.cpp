class Solution {
public:
    TreeNode* solve(vector<int>& preorder, int &i, int bound){
        //if whole vector is traversed or any elelement is greater than bound
        if(i == preorder.size() || preorder[i] > bound) return NULL;
        TreeNode* root = new TreeNode(preorder[i++]);//create node
        //for left every-ele should be less than bound(root->val)
        root->left = solve(preorder, i, root->val);
        //for right there INT_MAX is the max limit
        root->right = solve(preorder, i, bound);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return solve(preorder,i,INT_MAX);
    }
};
