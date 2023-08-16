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


//// same as Q.106 only preorder has root in start whereas postorder has root in end
class Solution {
public: 
//find index in inorder
    int find(vector<int>& inorder, int ele){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==ele) return i;
        }
        return -1;
    }


    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &index, int inStart, int inEnd){
        //boundary conditions
         if((index > preorder.size() || (inStart > inEnd))){
             return nullptr;
         }

         //ele of pre will be root
         int ele = preorder[index++];
         TreeNode* root = new TreeNode(ele);
         //find that pre index in inorder
         int pos = find(inorder,ele);

         root->left = solve(preorder, inorder, index, inStart, pos-1);//search in left for left subtree
         root->right = solve(preorder, inorder, index, pos+1, inEnd);//for right

         return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        TreeNode* ans = solve(preorder, inorder, index, 0, inorder.size()-1);   
        return ans;
    }
};
