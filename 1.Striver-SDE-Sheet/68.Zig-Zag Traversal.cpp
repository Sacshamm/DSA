class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {  
        vector<vector<int>>result;
        if(root == NULL) return result;
          queue<TreeNode*>q;
          q.push(root);
          int flag = 0;

          while(!q.empty()){
              int size = q.size();
              vector<int>ans;

              while(size--){
                TreeNode* node = q.front();
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

                ans.push_back(node->val);
              }

              //straight 1st lvl
              if(flag==0){
                  flag = 1;
                  result.push_back(ans);
              }
              //reversed 2nd lvl
              else{
                  reverse(ans.begin(),ans.end());
                  result.push_back(ans);
                  flag = 0;
              }        
          }
          return result;
    }
};
