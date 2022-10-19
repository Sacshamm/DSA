int findCeil(Node* root, int input) {
    int ceil = -1;
    if (root == NULL) return ceil ;
    //while(root){
        if(input == root->data){
            ceil = root->data;
            return ceil;
        }
        else if(input > root->data){
           // root = root->right;
           return findCeil(root->right,input);
        }
        else{
            ceil = root->data;
            //root = root->left;
            return findCeil(root->left,input);
        }
   // }
   
}
