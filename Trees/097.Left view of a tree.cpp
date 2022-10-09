void solve(Node*root, vector<int> &v , int level){
    if(root == NULL) return;
    
    if(v.size()==level) // For first node in each level everytime ans.size increases level also increases
        v.push_back(root->data);
    
    solve(root->left,v,level+1);
    solve(root->right,v,level+1);
}

vector<int> leftView(Node *root){
    
   vector<int>v;
   solve(root,v,0);
   return v;
}
