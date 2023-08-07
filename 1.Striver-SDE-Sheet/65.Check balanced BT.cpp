int height(TreeNode*node){
       if(node==nullptr) return 0;
       int l=height(node->left);
       int r=height(node->right);
       int maxi = max(l,r)+1;
       return maxi;
    }

    //balance bt is one which has left and right node level difference <=1
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;

        bool leftNode = isBalanced(root->left);
        bool rightNode = isBalanced(root->right);
        bool difference = abs(height(root->left)-height(root->right))<=1;

        if(leftNode && rightNode && difference) return true;
        else return false;
    }
