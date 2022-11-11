class Solution {
    private:
     void dfs(int node,int V, vector<int> adj[],int vis[], vector<int>&ans){
         vis[node] =1;
         ans.push_back(node);
         
         //traversing list of each node
         for(auto it:adj[node]){//when all nodes are travesed recursive func will stop
             if(!vis[it]){
                 //recursivce call for every list nodes
                 dfs(it,V,adj,vis,ans);
                 
             }
         }
     }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        int vis[V]={0};
        dfs(0,V,adj,vis,ans);
        
     return ans;
    }
};
