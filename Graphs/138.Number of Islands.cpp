class Solution {
     
    private:
    void dfs(int r, int c, vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        
        if(r < 0 || r >= n || c < 0 || c >= m ) return;//checking boundaries
        if( grid[r][c]=='0' || grid[r][c]=='2') return;//if it is 0 or already visited

        grid[r][c] = '2';//marked visited
            //traversing all 4 directions
            dfs(r+1,c,grid);
            dfs(r-1,c,grid);
            dfs(r,c-1,grid);
            dfs(r,c+1,grid);
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;

        for(int r=0; r<n; r++){
            for(int c=0; c<m; c++){
                //if it is land('1') then start traversing
                if(grid[r][c] == '1'){
                    islands++;//new 1 then inc.
                    dfs(r,c,grid);
                }
            }
        }
        return islands;
    }
};
