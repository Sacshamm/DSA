/     // extra space for vector
// class Solution {
// public:
//     void solve(TreeNode* root, vector<int> &v){
//         if(root == nullptr) return;
//         solve(root->left,v);
//         v.push_back(root->val);
//         solve(root->right,v);

//     }
//     bool isValidBST(TreeNode* root) {
//         vector<int>v;
//         solve(root, v);

//         for(int i=0;i<v.size()-1;i++){
//             if(v[i]>=v[i+1]) return false;
//         }
//      return true;
//     }
// };

//   //O(n) , auxilary recursive stack space O(1)
class Solution {
public:
    bool solve(TreeNode*root, long low,long high){
        if(root == NULL) return true;
        
        //val should be in range
        if(root->val < high && root->val > low){
            //for left root->val is the high and all val should be less than that.
            //for right root->val is the low and all val should be grater than that.
            //when both satisfies the cond. return true.
            return solve(root->left,low,root->val) && solve(root->right,root->val,high);
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,LONG_MIN,LONG_MAX);
    }
};


