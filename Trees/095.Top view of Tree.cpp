class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int>ans;
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        
        while(!q.empty()){
            
            auto it = q.front();
            q.pop();
            Node*node = it.first;
            int v_line = it.second;
            
            if(mp.find(v_line)==mp.end()) 
               mp[v_line]=node->data;
               
             if(node->left)
               q.push({node->left,v_line - 1});
              
             if(node->right)
               q.push({node->right,v_line + 1});
        }
        
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }

};
