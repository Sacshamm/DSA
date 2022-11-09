public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int v, vector<int> adj[]) {
         vector<int>bfs;
         int vis[v]={0};
         queue<int>q;
         q.push(0);
         vis[0]=1;
        
         
         while(!q.empty()){
             int node = q.front();
             q.pop();
             bfs.push_back(node);
             
             //traverse all the node inside adjancecy list .
             //if the node is not visited then push all the nodes associated with thast node into queue
             for(auto it:adj[node]){
                 if(vis[it] != 1){
                     q.push(it);
                     vis[it]=1;
                 }
             }
         }
         
        return bfs;
    }
};


//  //BFS for Disconnected Graph:
// vector<int> bfsOfGraph(int V, vector<int> adj[]){
//     vector<int> bfs_traversal;
//     vector<bool> vis(V, false);
//     for (int i = 0; i < V; ++i) {
        
//         // To check if already visited
//         if (!vis[i]) {
//             queue<int> q;
//             vis[i] = true;
//             q.push(i);
            
//             // BFS starting from ith node
//             while (!q.empty()) {
//                 int g_node = q.front();
//                 q.pop();
//                 bfs_traversal.push_back(g_node);
//                 for (auto it : adj[g_node]) {
//                     if (!vis[it]) {
//                         vis[it] = true;
//                         q.push(it);
//                     }
//                 }
//             }
//         }
//     }
//     return bfs_traversal;
// }
