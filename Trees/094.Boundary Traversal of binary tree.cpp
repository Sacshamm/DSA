class Solution {
public:
    void traverseLeft(Node* root, vector<int> &ans){
       if(root==NULL) return;
       
       if(root->left==NULL && root->right==NULL) return;
       
       ans.push_back(root->data);
       
       if(root->left) traverseLeft(root->left, ans);
       else traverseLeft(root->right, ans);
    }
    
    void traverseLeaf(Node* root, vector<int> &ans){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL) {
            ans.push_back(root->data);
            return;
        }
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }
    
     void traverseRight(Node* root, vector<int> &ans){
       if(root==NULL) return;
       
       if(root->left==NULL && root->right==NULL) return;
       
       
       if(root->right) traverseRight(root->right, ans);
       else traverseRight(root->left, ans);
       //for reverse order printing
       ans.push_back(root->data);

    }
    
    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        if(root==NULL) return ans;
        
        //printing root node
        ans.push_back(root->data);
        
        //left subtree excluding leaf node
        traverseLeft(root->left,ans);
        
        //only leaf nodes
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);
        
        //right subtree excluding leaf nodes
        traverseRight(root->right,ans);
        
        return ans;
    }
};
