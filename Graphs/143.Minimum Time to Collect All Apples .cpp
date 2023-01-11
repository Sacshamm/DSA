
class Solution {
public:
    int dfs(int node, int parent,vector<vector<int>> &adj, vector<bool>& hasApple){
        int dist_frm_root = 0;//from top node i.e root
        for(auto i:adj[node]){
            if(i!=parent){
             //calculating distance at each step for its childs 
              int distance_frm_parent = dfs(i,node,adj,hasApple);
                 if(hasApple[i]){// if the node is apple
              //adding distance of each node back to parent
                  dist_frm_root += (distance_frm_parent+2);
                  hasApple[node] = true;// also mark parent as apple to calculate distance while returning back
              }
            }
        }
         return dist_frm_root;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>adj(n);
        
        //making an adj list
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        return dfs(0,-1,adj,hasApple);
    }
};
