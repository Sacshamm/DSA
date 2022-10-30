class Solution{
public:
    vector<int> v;
    int idx=0;
  //getting inorder of BST
      void inorder(Node* root){
          if(!root){
              return;
          }
          inorder(root->left);
          v.push_back(root->data);
          inorder(root->right);
      }
      
      //converting that inorder to postorder to get MAX HEAP
       void postorder(Node* root){
            if(!root){
                return;
            }
            postorder(root->left);
            postorder(root->right);
            root->data=v[idx++];
        }
      
        void convertToMaxHeapUtil(Node* root)
        {
            // Your code goes here
            inorder(root);
            postorder(root);
        }     
};
