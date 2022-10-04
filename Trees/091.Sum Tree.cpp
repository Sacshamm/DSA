class Solution
{
    public:
    // check if sum of left + right == root
    // first= true if the subtree satisfies the above condidtion and second contains the sum
    pair<bool,int> solve(Node*root){
        if(root==NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        if(root->left ==NULL && root->right == NULL){
            pair<bool,int> p = make_pair(true,root->data);
            return p;
        } 
        
        pair<bool,int> leftNode= solve(root->left);
        pair<bool,int> rightNode= solve(root->right);
        
        bool left= leftNode.first;
        bool right= rightNode.first;
        bool check= leftNode.second + rightNode.second == root->data;
        
        pair<bool,int> ans;
        if(left && right && check) {
            ans.first = true;
            ans.second = leftNode.second + rightNode.second + root->data;
        }
        else ans.first=false;
        
        return ans;
    }
    
    bool isSumTree(Node* root)
    {
         return solve(root).first;
    }
};
