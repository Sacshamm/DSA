//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//bfs
class Solution {
    private:
    bool detect(int src, vector<int>&vis, vector<int> adj[]){
        vis[src]=1;//mark visited
        queue<pair<int,int>>q;
        q.push({src,-1});//node with parent node
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto adjnode:adj[node]){
                if(!vis[adjnode]){//if the node is not visited
                    vis[adjnode]=1;//mark it visited
                    q.push({adjnode,node});//push it along with its parent node
                }
//if it is visited, then it must pe a parent itself or a node that is visited by another node
                else if(adjnode!=parent){//if it is not a parent then there is a cycle
                //bcz before visting some other node had already visited it.
                  return true;   
                }
            }
        }
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        //int vis[V]={0};
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){//there may be diff. components of graph thats why traverse
            if(!vis[i]){
                if(detect(i,vis,adj)==true) return true;
            }
        }
        return false;
    }
};





// //dfs
// class Solution {
//   public:
//   bool dfs(int i,int parent,int v,vector<int> adj[],vector<int> &vis){
//         vis[i] = 1;

//         for(auto it:adj[i]){
//             if(vis[it]==0){
//                 if(dfs(it,i,v,adj,vis)==true) return true;
//             }
//             else if(vis[it]==1 && it!=parent) return true;
//         }
//         return false;
//   }
//     // Function to detect cycle in an undirected graph. 0.73
//     bool isCycle(int v, vector<int> adj[]) {
//         vector<int> vis(v,0);
//         for(int i =0;i<v;i++){
//             if(vis[i]!=1){
//                 if(dfs(i,-1,v,adj,vis)==true)
//                   return true;
//             }
//         }
//         return false;
//     }
// };

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
