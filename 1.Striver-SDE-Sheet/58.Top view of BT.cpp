class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        queue<pair<Node*,int>>q;//node,level
        map<int,int>mp;//level,node->val
        
        q.push({root,0});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            Node* node = it.first;
            int position = it.second;
            
            //if position is visited first time then only insert in map
            if(mp.find(position)==mp.end()){
                mp[position] = node->data;
            }
            
            if(node->left) q.push({node->left,position-1});
            if(node->right) q.push({node->right,position+1});
        }
        
        vector<int>ans;
        
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }

};
