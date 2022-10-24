class BSTIterator {
public:
  // O(H) time
    stack<TreeNode*>st;
    void pushAll(TreeNode* node){
           while(node!=nullptr) {
           st.push(node);
           node=node->left;
       }
    }
    BSTIterator(TreeNode* root) {
       //push evry node in stack
      pushAll(root);
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        if(st.empty()) return false;
        return true;
    }
};


// O(n) time
// class BSTIterator {
// public:
//     vector<int>v;
//     int i=-1;
//     int n;

//     void inorder(TreeNode* root){
//         if(root==nullptr) return ;

//         inorder(root->left);
//         v.push_back(root->val);
//         inorder(root->right);
//     }
//     BSTIterator(TreeNode* root) {
//         inorder(root);
//         n=v.size();
//     }
    
//     int next() {
//         i++;
//         return v[i];
//     }
    
//     bool hasNext() {
//          int x=i;
//           x++;
//         if(x<n)
//             return true;
//         else
//             return false;
//     }
// };
