class Solution {
public:
// store inorder in vector and perform basic two sum on the vector
    void inorder(TreeNode*root, vector<int> &v){
        if(root==nullptr) return;

        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>v;
        inorder(root,v);
        int i=0; int j=v.size()-1;
        while(i<j){
            if(v[i]+v[j]==k) return true;
            else if(v[i]+v[j] > k) j--;
            else i++;
        }
        return false;
    }
};
