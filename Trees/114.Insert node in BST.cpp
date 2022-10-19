class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        bool flag = false;
            if(root == nullptr){
                return new TreeNode(val);
                flag = true;
            }

         TreeNode*cur = root;
            while(flag == false){
                if(cur->val <= val){
                    if(cur->right!=nullptr)
                        cur = cur->right;
                    else{
                        cur->right = new TreeNode(val);
                        flag= true;
                    }
                }
                else{
                    if(cur->left!=nullptr)
                        cur = cur->left;
                    else{
                        cur->left = new TreeNode(val);
                        flag= true;
                    }
                }
            }
         return root;
    }
};
