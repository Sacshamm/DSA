void solve(Node *root, int k, int node , int & result , vector<int>ans)

{

    if( root == NULL) return;

    if(root->data == node){
        
     int size = ans.size();
     
         for(int i = size - 1; i>=0; i--){
               if(i == size-k){
                 result = ans[i];
                 break;
                }
            }
        }
     ans.push_back(root->data);

     solve(root->left , k , node , result , ans);
     solve(root->right , k , node , result , ans);
     ans.pop_back();

}

int kthAncestor(Node *root, int k, int node)
{
   int result = -1;
   vector<int>ans;
   solve(root , k , node , result , ans);
   
   return result;

   

}
