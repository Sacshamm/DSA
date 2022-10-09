 void solve(Node*root, map<int,vector<int>> &mp, int diagnol){
        if(root == NULL) return;
        
        mp[diagnol].push_back(root->data);
/*we have to print diagnol from L to R and L should be keep on changing(bcz diagnol have to change after 
every level on left side*/

        solve(root->left,mp,diagnol+1);
        solve(root->right,mp,diagnol);//right should be kept constant according to root node to map accordingly
}
    vector<int> diagonal(Node *root){
        
         vector<int>ans;
         map<int,vector<int>>mp;//mapping of diagnoal with various nodes(vector)
         solve(root,mp,0);
   
   //traversing second inside map which is vector
         for(auto x:mp){
            for(auto i:x.second)
                 ans.push_back(i);
            }
        return ans;
}
