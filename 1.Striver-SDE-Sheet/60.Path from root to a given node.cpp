bool  helper(TreeNode*root, int B, vector<int> &ans){
     if(!root) return false;
     ans.push_back(root->val);//push every node which comes
     
     if(root->val == B) return true;//if on the right path and reaches leaf 
     
     bool left = helper(root->left,B,ans);
     bool right = helper(root->right,B,ans);
     
     if(left || right) return true;//if either of the call reaches to that target leaf node ret true
     
     ans.pop_back();//if not the right path then remove that node and return to previous state in vector
     return false;//and return false if not got from that part
 }
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>ans;
    helper(A,B,ans);
    return ans;
}
