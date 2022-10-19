class Solution {
public:

// to find the last right node of left subtree
TreeNode* find(TreeNode*root){
    while(root->right!= nullptr){
        root=root->right;
    }
    return root;
}


TreeNode* deleteAndUpdate(TreeNode* root){
    if(root->left == nullptr){
        return  root->right;
    }
    if(root->right == nullptr){
        return  root->left;
    }

    TreeNode* rightChild = root->right;//right child of the node that is supossed to be deleted
    TreeNode* lastRightChild_of_left = find(root->left);//last right node of left subtree 
    lastRightChild_of_left->right = rightChild;//connecting right subtree with last right node of left subtree
    return root->left;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if(root == nullptr) return nullptr;

    TreeNode* cur = root;// bcz we have to return root at end

    if(root->val == key){
        return deleteAndUpdate(root);
    }

    while(root){
        if(root->val < key){//right
            if(root->right!= nullptr && root->right->val == key){
                root->right = deleteAndUpdate(root->right);
            }
            else{
                root = root->right;
            }
        }
        else{//left
            if(root->left!= nullptr && root->left->val == key){
                root->left = deleteAndUpdate(root->left);
            }
            else{
                root = root->left;
            }
        }
    }
    return cur;
  }
};
