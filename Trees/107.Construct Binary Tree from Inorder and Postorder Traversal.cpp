class Solution {
public:
    int findPos(vector<int>& inorder, int &ele){
        for(int i=0;i<inorder.size();i++){
            if(ele == inorder[i]) return i;
        }
        return -1;
    }
   TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int &index, int inStart, int inEnd){
        if((index < 0) || (inStart > inEnd))
           return nullptr;
    
        int ele = postorder[index--];
        TreeNode* root = new TreeNode(ele);
        int pos = findPos(inorder,ele);

        root->right = solve(inorder, postorder, index, pos+1, inEnd);
        root->left = solve(inorder, postorder, index, inStart, pos-1);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int index = n-1;
        TreeNode* ans = solve(inorder, postorder, index, 0, inorder.size()-1);
        return ans;
    }
};
