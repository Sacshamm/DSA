class Solution {
public:
    void solve(TreeNode*root,int targetSum,vector<int>v,int &count){
        if(root == nullptr) return;

        v.push_back(root->val);

        solve(root->left,targetSum,v,count); 
        solve(root->right,targetSum,v,count); 
        
        long long Sum=0;
        for(int i=v.size()-1; i>=0; i--){
            Sum += v[i];
            if(Sum == targetSum) count++;
        }
        v.pop_back();
    }

    int pathSum(TreeNode* root, int targetSum) {
        vector<int>v;
        int count=0;
        solve(root,targetSum,v,count); 
        return count;
    }
};
