class Solution {
public:
    void solve(TreeNode*root, vector<int> &v, int level){
       if(root == nullptr) return;

       if(v.size() == level) v.push_back(root->val);

       solve(root->right,v,level+1);
       solve(root->left,v,level+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
        solve(root, v , 0);
        return v;
    }
};
