class Solution {
public:
    // int height(TreeNode*node){
    //    if(node==nullptr) return 0;
    //    int l=height(node->left);
    //    int r=height(node->right);
    //    int maxi = max(l,r)+1;
    //    return maxi;
    // }

    // bool isBalanced(TreeNode* root) {
    //     if(root==nullptr) return true;

    //     bool leftNode = isBalanced(root->left);
    //     bool rightNode = isBalanced(root->right);
    //     bool difference = abs(height(root->left)-height(root->right))<=1;

    //     if(leftNode && rightNode && difference) return true;
    //     else return false;
    // }
    ////same logic just a diff way
    // bool isBalanced(TreeNode* root) {
    //     if(root==nullptr) return true;
         
    //     bool difference = abs(height(root->left)-height(root->right))<=1;
    //     if(!difference) return false; 
    //     bool leftNode = isBalanced(root->left);
    //     bool rightNode = isBalanced(root->right);

    //     if(leftNode && rightNode ) return true; 
    //     else return false;
    //   }
    
      ////O(n)
      pair<bool,int>solve(TreeNode* node){
          if(node==nullptr){
          pair <bool,int> p=make_pair(true,0);
          return p;
          }
          pair <bool,int>leftNode= solve(node->left);
          pair <bool,int>rightNode= solve(node->right);
          
          bool leftBalanced=leftNode.first;
          bool rightBalanced=rightNode.first;
          bool difference= abs(leftNode.second-rightNode.second)<=1;

          pair <bool,int> ans;
         // ans.first= difference;
          ans.second= max(leftNode.second,rightNode.second)+1;

          if(leftBalanced && rightBalanced && difference)  ans.first = true;
          else ans.first=false;
          
          return ans;
      }

       bool isBalanced(TreeNode* root) {
           return solve(root).first;
       }
};
