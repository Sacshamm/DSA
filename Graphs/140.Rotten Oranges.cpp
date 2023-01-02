
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        if (grid.empty()) // if there is no orange.
            return 0;

        int countFreshOranges = 0;
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q; // queue to store the index of the cell where rotten oranges are placed.

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    countFreshOranges++;
                else if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }

        int time = 0;
        // four adjacent positions at which the oranged placed will get rotten.
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        while (countFreshOranges != 0 && !q.empty())
        {
            int qsize = q.size();

            for (int i = 0; i < qsize; i++)
            {
                int rottenI = q.front().first;
                int rottenJ = q.front().second;
                q.pop();

                for (auto d : dirs)
                {
                    int newX = rottenI + d.first;
                    int newY = rottenJ + d.second;
                    // if we got any fresh orange adjacent to the rotten orange then it will get rotten and
                    // count of fresh oranges will reduce and we will push the new index of rotten orange in 
                    // the queue.
                    if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1)
                    {
                        grid[newX][newY] = 2;
                        countFreshOranges--;
                        q.push({newX, newY});
                    }
                }
            }
            time++;
        }
        if(countFreshOranges == 0) return time; 
         
         return -1;
    }
};

////tried but not working
// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         int vis[n][m];
//         queue < pair<pair<int, int>, int>>q;

//         for (int i = 0; i < n; i++){
//             for (int j = 0; j < m; i++){
//                 if(grid[i][j]==2){
//                     q.push({{i, j}, 0});
//                     vis[i][j]=2;
//                 }
//                 else{
//                     vis[i][j]=0;
//                 }
//             }
//         }
//         int time = 0;
//         int deltaRow[4]= {-1,0,1,0};
//         int deltaCol[4]= {0,1,0,-1};

//         while(!q.empty()){
//             int row= q.front().first.first;
//             int col= q.front().first.second;
//             int t= q.front().second;
//             //time = max(time,t);
//             q.pop();
//             for(int i=0;i<4;i++){
//                 int nRow = row + deltaRow[i];
//                 int nCol = col + deltaCol[i];
//             if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && grid[nRow][nCol]==1 && vis[nRow][nCol]!=2){
//                 q.push({{nRow,nCol},t+1});
//                 vis[nRow][nCol]=1;
//             }
//         }
//     }

//              for (int i = 0; i < n; i++){
//                   for (int j = 0; j < m; i++){
//                       if(grid[i][j]==1 && vis[i][j]!=2){
//                           return -1;
//                 }
//             }
//         }
      
//       return time;
//     }
// };
