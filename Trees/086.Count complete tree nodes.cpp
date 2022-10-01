/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ////brute force visit each node and count every node takes O(n) time
    // void inorder(TreeNode* root , int &count){
    //     if(root==nullptr) return;

    //     inorder(root->left,count);
    //     count++;
    //     inorder(root->right, count);
    // }
    // int countNodes(TreeNode* root) {
    //     int count=0;
    //     inorder(root ,count);
    //     return count;
    // }

    int countingLeftNodes(TreeNode* node){//simply counting height of left subtree
        int ht;
        while(node){
            node=node->left;
            ht++;
        }
        return ht;
    }

    int countingRightNodes(TreeNode* node){//counting heihght of right subtree
        int ht;
        while(node){
            node=node->right;
            ht++;
        }
        return ht;
    }
    
    int countNodes(TreeNode* root){
       if(root == nullptr) return 0;

       int l= countingLeftNodes(root);// total height of left subtree at particular node
       int r= countingRightNodes(root);// total height of right subtree at particular node
//(if it is a full BT then simply it is 2 to the pow of height of either l or r)-1
       if(l==r)
       return pow(2,l)-1;
//recursive call at for left and right subtree in case it is not a full BT or only left subtree part is complete.
       return 1+countNodes(root->left)+countNodes(root->right);

    }
};
