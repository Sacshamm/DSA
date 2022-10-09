class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int>ans;
        map<int,int>mp;//vline , node data ka pair
        
        queue<pair<Node*,int>>q;//node , vline ka pair
        q.push({root,0});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node*node = it.first;
            int v_line = it.second;
            
            mp[v_line]=node->data;//no need to check for duplicate, just put elemnts and the ele at last will be answer.
            
            if(node->left){
                q.push({node->left,v_line - 1});
            }
            if(node->right){
                q.push({node->right,v_line + 1});
            }
        }
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
        
    }
};
