class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr) return result;
        bool leftToRight = true;//flag to check whether from L->R or R->L
        
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();//gets updated after every level
            vector<int>ans(size);// used inside loop
            
            for(int i=0;i<size;i++){
                TreeNode* frontNode = q.front();
                q.pop();

                int index;
                if(leftToRight == true) index=i;
                else index = size-1-i;//reversing

                ans[index] = frontNode->val;

                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
         }
           leftToRight = !leftToRight;//transferring the flow from L->R to R->L
           result.push_back(ans);
        }
      return result;
    }
};
