class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        Node* successor = NULL;
        //we have to search for element just greater than x->data
        while(root!= NULL){
            //if x is breater than root , so move to right and look for more greater ones
            if(x->data >= root->data){
                root = root->right;
            }
            else{
            //if found less than or = x->data  then it might be a successor so store it    
                successor = root;
            //also move to left to check if there is any element which is just greater than x->data    
                root = root->left;
            }
        }
        return successor;
    }
};
