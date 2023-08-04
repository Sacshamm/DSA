//left view

void solve(Node*root, vector<int>&ans, int level){
    if(!root) return;
    
    if(ans.size()==level) ans.push_back(root->data);//ensure that only first element is stored
    
    solve(root->left,ans,level+1);
    solve(root->right,ans,level+1);
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>ans;
   int level=0;
   solve(root,ans,level);
   return ans;
}


//right view
void solve(Node*root, vector<int>&ans, int level){
    if(!root) return;
    
    if(ans.size()==level) ans.push_back(root->data);//ensure that only first element is stored

    solve(root->right,ans,level+1);
    solve(root->left,ans,level+1);
    
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>ans;
   int level=0;
   solve(root,ans,level);
   return ans;
}
