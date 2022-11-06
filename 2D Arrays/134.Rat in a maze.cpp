class Solution{
   private:
    
    bool isSafe(vector<vector<int>> &m, int n, int x, int y, vector<vector<int>>visited ) {
        //if x and y are out of bound then its false
        if( (x>=0 && x<n) && (y>=0 && y<n ) && (m[x][y]==1) && (visited[x][y]==0) ){
            return true;
        }
        return false;
    }
    
    void solve(vector<vector<int>> &m, int n,int x,int y, vector<string> &ans,
               string path, vector<vector<int>> visited){
                
                if(x == n-1 && y==n-1){
                   ans.push_back(path);
                   return;
                }
                
                visited[x][y] = 1;
                
                //down
                if(isSafe(m, n, x+1, y, visited)){
                    path.push_back('D');
                    solve(m,n,x+1,y,ans,path,visited);
                    path.pop_back();
                }
                
                //left
                if(isSafe(m, n, x, y-1, visited)){
                    path.push_back('L');
                    solve(m,n,x,y-1,ans,path,visited);
                    path.pop_back();
                }
                
                //right
                if(isSafe(m, n, x, y+1, visited)){
                    path.push_back('R');
                    solve(m,n,x,y+1,ans,path,visited);
                    path.pop_back();
                }
                
                //up
                if(isSafe(m, n, x-1, y, visited)){
                    path.push_back('U');
                    solve(m,n,x-1,y,ans,path,visited);
                    path.pop_back();
                }
                //mark visited 0 when returning from destination
                visited[x][y] = 0;
              }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        
        if(m[0][0] == 0) return ans;
        
        int srcx=0;
        int srcy=0;
        
        vector<vector<int>> visited = m;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j] = 0;
            }
        }
        
        string path="";
        solve(m,n,srcx,srcy,ans,path,visited);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
