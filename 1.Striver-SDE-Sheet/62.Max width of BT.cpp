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

 //left 2*i+1 and for right 2+i+2
 //imagine tree in the form of array  starting from index 0
class Solution {
public: 
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ll>>q;
        q.push({root,0});//node and index
        ll maxWidth = 0;

         while(!q.empty()){ 
             int size = q.size();
             //front will point to index of first node of each level
             ll leftNode = q.front().second;
             //back will point to index of last node of each level
             ll rightNode = q.back().second;
            //difference can be easily calculated using indexes
             maxWidth = max(maxWidth, rightNode-leftNode+1);

                while(size--){
                    TreeNode* node = q.front().first;
                    ll idx = q.front().second;
                    q.pop();
                    if(node->left) q.push({node->left,2*idx+1});
                    if(node->right) q.push({node->right,2*idx+2});
                }
         }
         return maxWidth;
    }
};
