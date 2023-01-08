class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
       //double pair to store index and count how many steps taken from 0->1
        queue<pair<pair<int,int>,int>>q;
        
        //vis and dis. Dis stores the distance from 0->1
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){// if 0 then proceed
                    vis[i][j]=1;//mark visited
                    q.push({{i,j},0});
                }
                else vis[i][j]=0;
            }
        }
        int delR[] = {1,0,-1,0};
        int delC[] = {0,-1,0,1}; 
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            dist[row][col] = steps;//assigning steps to the dist matrix

            for(int i=0;i<4;i++){
                int new_row = row + delR[i];
                int new_col = col + delC[i];

            if(new_row>=0 && new_row<n && new_col>=0 && new_col<m && vis[new_row][new_col]==0){
                //adding steps to previous
                //note: if there is a zero 
                  q.push({{new_row,new_col},steps+1});
                  vis[new_row][new_col]=1;
              }
           }
        }
        return dist;
    }
};
