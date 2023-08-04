class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int>ans;
        queue<pair<Node*,int>>q;
        map<int,int>mp;//level,node
        q.push({root,0});//node,level
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int position = it.second;
            
            mp[position] = node->data;//store value at that positon
            
            if(node->left) q.push({node->left,position-1});
            if(node->right) q.push({node->right,position+1});
        }
        
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
