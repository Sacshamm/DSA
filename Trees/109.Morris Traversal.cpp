
// For inorder


class Solution{
  
  vector<int>getinorder(Node*root){
    vector<int>inorder;
    Node*cur = root;
       while(cur!=NULL){
         // if there is  no left print the root and move right
         if(cur->left =  NULL){
             inorder.push_back(cur->val);
             cur=cur->right;
          }
         else{
           Node*prev = cur->left;
           //move to the right most leaf node of left sub tree.
              while(prev->right && prev->right!=cur){
                  prev = prev->right;
              }
             //when reached make a link between that node and cur node(root node) and move to left.
             if(prev->right = NULL){
                 prev->right = cur;
                 cur = cur->left;
             }
             //if link is already there then remove link print root and move right
             else{
               prev->right = NULL;
               inorder.push_back(cur->val);
               cur = cur->right;
             }
         }
      }
     return inorder;
  }
  
};



// For preorder

// For inorder


class Solution{
  
  vector<int>getinorder(Node*root){
    vector<int>preorder;
    Node*cur = root;
       while(cur!=NULL){
         // if there is  no left print the root and move right
         if(cur->left =  NULL){
             inorder.push_back(cur->val);
             cur=cur->right;
          }
         else{
           Node*prev = cur->left;
           //move to the right most leaf node of left sub tree.
              while(prev->right && prev->right!=cur){
                  prev = prev->right;
              }
             //when reached make a link between that node and cur node(root node) then print root and move to left.
             if(prev->right = NULL){
                 prev->right = cur;
                 preorder.push_back(cur->val);
                 cur = cur->left;
             }
             //if link is already there then remove link and move right
             else{
               prev->right = NULL;
               cur = cur->right;
             }
         }
      }
     return preorder;
  }
  
};
  
