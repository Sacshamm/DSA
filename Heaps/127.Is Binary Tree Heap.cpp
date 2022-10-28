class Solution {
  public:
  
  bool isHeap(struct Node* root) {
       queue<Node*>q;
       bool flag=false;
       q.push(root);
       while(!q.empty())
       {
           Node *t=q.front();
           q.pop();
           
      
           if(t->left){
               //if any child is greater and falg is true return false
               //here flag is used to determine if tree is complete or not.
               //if a node's left is not present the  flag will change and at the next step it will return false
               if(t->data < t->left->data||flag==true) 
               return false;
               q.push(t->left);
           }
           else{
               flag=true;
           }
           
           
           if(t->right){
               if(t->data < t->right->data||flag==true)
               return false;
               q.push(t->right);
           }
           else{
               flag=true;
           }
       }
      
       return true;
    }
};
