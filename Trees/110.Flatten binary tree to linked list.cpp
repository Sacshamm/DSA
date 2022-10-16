
 //recursive
// class Solution {
// public:   
// TreeNode* prev = nullptr;
//     void flatten(TreeNode* root) {
   
//         if(root==NULL) return;

//         flatten(root->right);
//         flatten(root->left);

//         root->right = prev;
//         root->left = NULL;

//         prev = root;
//         return;
//     }
// };




//iterative + stack 
// class Solution {
// public:
//     void flatten(TreeNode* root) {
//         stack<TreeNode*> s;

//         if(root) s.push(root);

//         while(!s.empty()){
//             auto p = s.top();
//             s.pop();
//             if(p -> right) s.push(p -> right);
//             if(p -> left)  s.push(p -> left);
//             if(!s.empty()) p -> right = s.top();
//             p -> left = nullptr;
//         }
//     }
// };




//Morris traversal O(n),O(1)
class Solution {
public:
    void flatten(TreeNode* root){
        TreeNode*curr = root;
        if(curr==nullptr) return;
         while(curr!=NULL){
            if(curr->left == NULL) curr = curr->right;
            else{
            TreeNode*prev = curr->left; 
              while(prev->right && prev->right!=curr->right){
                  prev = prev->right;
              }
              prev->right = curr->right;
              curr->right = curr->left;
              curr->left = nullptr;
            }
         }
    }      
};
