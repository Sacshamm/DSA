class Solution {
public: 
    int find(vector<int>& inorder, int ele){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==ele) return i;
        }
        return -1;
    }

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &index, int inStart, int inEnd){
         if((index > preorder.size() || (inStart > inEnd))){
             return nullptr;
         }

         int ele = preorder[index++];
         TreeNode* root = new TreeNode(ele);
         int pos = find(inorder,ele);

         root->left = solve(preorder, inorder, index, inStart, pos-1);
         root->right = solve(preorder, inorder, index, pos+1, inEnd);

         return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       int n = inorder.size();
       int index = 0;
       TreeNode* ans = solve(preorder, inorder, index, 0, n-1);   
       return ans;
    }
};
