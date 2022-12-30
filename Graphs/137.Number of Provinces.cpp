class Solution {
public:
    void dfs(int node,vector<int> &vis,vector<int> adjLs[]){
              vis[node]=1;

            for(auto it : adjLs[node]){
                if(vis[it]!=1){
                    dfs(it,vis,adjLs);
                }
            }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
            int V = isConnected[0].size();
            vector<int> adjLs[V];
          //Converting Adjacency matrix to Adjacency list
          for(int i=0;i<V;i++){
              for(int j=0;j<V;j++){
                  
                  if(isConnected[i][j]==1 && i!=j){
                      adjLs[i].push_back(j);
                      adjLs[j].push_back(i);
                  }
              }
          }
        vector<int>vis(V,0);
        int count=0;
        //if the node is not visited then increase the count.
        for(int i=0;i<V;i++){
            if(vis[i] != 1){
                count++;
                 dfs(i,vis,adjLs);
            }
           
            
        }
        return count;
    }
};
