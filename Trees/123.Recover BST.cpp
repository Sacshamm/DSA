class Solution {
    private:
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;

    private:
    void solve(TreeNode* root){
        if(root == nullptr) return;

        solve(root->left);
        if(prev!=NULL && (prev->val > root->val)){
            //storing first voilation
            if(first == NULL){
                first = prev;
                middle = root;
            }
            //storing second voilation
            else
               last = root;
        }
        //moving prev ahead
        prev=root;
        solve(root->right);
    }

    
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        solve(root);
        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
    }
};






// //T.C = O(nlogn) for sorting + O(n) for inorder + O(n) for comparing
// //S.C = O(n) for storing inorder in vector + recursion stack space

// //find inorder of tree , sort it and then simply transfer that values into orignal bst
// class Solution {
// public:
// int i=0;
//     void sorted_vector(TreeNode*root, vector<int>&v){
//         if(root == nullptr) return;
//         sorted_vector(root->left,v);
//         v.push_back(root->val);
//         sorted_vector(root->right,v);

//         sort(v.begin(),v.end());
//     }
//     void comapare(TreeNode*root, vector<int>&v){
        
//         if(root!=nullptr){
//         comapare(root->left,v);
//         root->val = v[i++];
//         comapare(root->right,v);
//         }
//     }
//     void recoverTree(TreeNode* root) {
//         vector<int>v;
//         sorted_vector(root,v);
//         comapare(root,v);
//     }
// };
