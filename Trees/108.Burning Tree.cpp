class Solution {
public:
    // map a node with its parent and find the start node in a tree
    TreeNode* creatMapping(TreeNode* root, map<TreeNode*,TreeNode*> &nodeToParent, int start){
          queue<TreeNode*>q;
          q.push(root);

          nodeToParent[root] = nullptr;
          TreeNode* ans = nullptr;

          while(!q.empty()){
              TreeNode* front = q.front();
              q.pop();

              if(start == front->val) ans=front;

              if(front->left){
                  nodeToParent[front->left] = front;
                  q.push(front->left);
              }

              if(front->right){
                  nodeToParent[front->right] = front;
                  q.push(front->right);
              }
          }
          return ans;
    }
    
    //burning starts
    int burningTree(TreeNode* root,map<TreeNode*,TreeNode*> &nodeToParent){

        map<TreeNode*,bool> visited;
        queue<TreeNode*>q;
        q.push(root);
        visited[root] = true;
        int time=0;

        while(!q.empty()){
            int size = q.size();
            bool flag = false;

            for(int i=0;i<size;i++){
                TreeNode* front = q.front();
                q.pop();

                if(front->left && !visited[front->left]){
                    flag = true;
                    visited[front->left] = true;
                    q.push(front->left);
                }

                 if(front->right && !visited[front->right]){
                     flag = true;
                    visited[front->right] = true;
                    q.push(front->right);
                }

                 if(nodeToParent[front] && !visited[nodeToParent[front]]){
                     flag = true;
                    visited[nodeToParent[front]] = true;
                    q.push(nodeToParent[front]);
                }
            }
            if(flag == true) time++;
        }
       return time;
    }
    
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> nodeToParent;

        TreeNode* targetNode = creatMapping(root, nodeToParent, start);
        int ans = burningTree(targetNode, nodeToParent);
        return ans;
    }
};
