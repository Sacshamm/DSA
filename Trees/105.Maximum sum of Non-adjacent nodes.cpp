class Solution{
  public:
  // pair.first= values including current node and pair.second= values excluding current node
    pair<int,int> solve(Node*root){
        if(root==NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> leftans = solve(root->left);
        pair<int,int> rightans = solve(root->right);
        
        pair<int,int> res;
        res.first = root->data + leftans.second + rightans.second;//curr node + child,s child for left and right
        res.second = max(leftans.first, leftans.second) + max(rightans.first, rightans.second);//excluding curr node 
        
        
        return res;
    }
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root){
        pair<int,int>ans = solve(root);
        return max(ans.first, ans.second);
    }
};
