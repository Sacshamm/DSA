// Consider a tree
// 5
// / \
// 4 3
// sum=9

// 9-5=4
// Now updated sum for left and right node is 4
// left node(4) == sum(4) return true
// right node(3) == sum(4) return false

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        
        //condition for checking if there is a leaf node in path or not
        if(root->left == nullptr && root->right == nullptr){
               if(targetSum - root->val == 0) return true;
        }
//keep on checking for left & right subtree if it a correct path or not
        bool isLeftEqual = hasPathSum(root->left , targetSum-root->val);
        bool isRightEqual = hasPathSum(root->right , targetSum-root->val);
//if anyone of them is correct then return true;
        return isLeftEqual || isRightEqual;
    }
};
