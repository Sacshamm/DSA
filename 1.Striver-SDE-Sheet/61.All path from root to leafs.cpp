
class Solution {
public:
    void solve(TreeNode * root, vector<string>&ans, string s){

        if(!root)return;

        s += to_string(root->val);//insert each path
        //when at leaf push in ans
        if(!root->left && !root->right){
            ans.push_back(s);
            return;
        }

        solve(root->left, ans, s+"->");
        solve(root->right, ans, s+"->");
    }

    vector<string> binaryTreePaths(TreeNode* root) 
    {
        string s = "";
        vector<string>ans;
        solve(root, ans, s);    
        return ans;
    }
};
