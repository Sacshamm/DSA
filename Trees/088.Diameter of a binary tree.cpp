class Solution {
public:
//  //brute force O(n^2) bcz we are finding left and right diameter which takes O(n) and    also calucalting heigt which also takes O(n) so O(n*n)
    // int height(TreeNode*node){
    //     if(node==0) return 0;
    //     int left = height(node->left);
    //     int right = height(node->right);
    //     int ans = max(left,right)+1;

    //     return ans;
    // }
    // int diameterOfBinaryTree(TreeNode* root) {
    //     if(root==nullptr) return 0;
    //    int leftd = diameterOfBinaryTree(root->left);
    //    int rightd = diameterOfBinaryTree(root->right);
    //    int heightFromRoot = height(root->left)+height(root->right);
       
    //    int maxi = max(heightFromRoot, max(leftd,rightd));

    //    return maxi;
    // }
     
    pair<int,int>solve(TreeNode*root){
        if(root==nullptr){
            pair<int,int> p= make_pair(0,0);
            return p;
        }

        pair<int,int>left = solve(root->left);
        pair<int,int>right = solve(root->right);

        int leftD = left.first;
        int rightD = right.first;
        int heightFromRoot = left.second + right.second +1;

         pair<int,int>ans;
         ans.first = max(heightFromRoot, max(leftD,rightD));
         ans.second = max(left.second,right.second)+1;

         return ans; 
    }

    int diameterOfBinaryTree(TreeNode* root){
         return solve(root).first;
    }
};
