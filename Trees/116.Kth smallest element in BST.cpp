class Solution {
public:
   //vector<int>v;
    //void inorder(TreeNode*root){
    //    if(root == NULL) return ;
    //    inorder(root->left);
    //     v.push_back(root->val);
    //     inorder(root->right);
// }

    int ans=0;
    void inorder(TreeNode*root,int &k){
        if(root == NULL) return ;
    
        inorder(root->left,k);
        k--;
        if(k == 0){
           ans = root->val;
          return;
        }
        inorder(root->right,k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
         return ans;
    }
};


