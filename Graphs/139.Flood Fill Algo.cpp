class Solution {
    private:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color,int og_color){

        if(sr<0||sr>=image.size()|sc<0||sc>=image[0].size()) return;//boundary check
        if(image[sr][sc]!=og_color || image[sr][sc]==color) return;//valid and non repetetive check for dfs

        image[sr][sc] = color;//mark
        //dfs in all 4 directions
        dfs(image,sr+1,sc,color,og_color);
        dfs(image,sr-1,sc,color,og_color);
        dfs(image,sr,sc+1,color,og_color);
        dfs(image,sr,sc-1,color,og_color);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int og_color = image[sr][sc];//storing orignal val
        dfs(image,sr,sc,color,og_color);
        
     return image;
    }
};


/////tried BFS but not working
// class Solution {
//     private:
//     void bfs(vector<vector<int>>& image, int sr, int sc, int color,int og_color){
//         image[sr][sc]=color;
//         queue<pair<int,int>>q;
//         q.push({sr,sc});

//         while(!q.empty()){
//             int x=q.front().first;
//             int y=q.front().second;
//             q.pop();
            
//             if(x>0 && image[x-1][y]==og_color && image[x][y]!=color){
// 				image[x-1][y]=color;
// 				q.push({x-1, y});
// 			}
// 			if(y>0 && image[x][y-1]==og_color && image[x][y]!=color){
// 				image[x][y-1]=color;
// 				q.push({x, y-1});
// 			}
// 			if(x<image.size() && image[x+1][y]==og_color && image[x][y]!=color){
// 				image[x+1][y]=color;
// 				q.push({x+1, y});
// 			}
// 			if(y<image[0].size() && image[x][y+1]==og_color && image[x][y]!=color){
// 				image[x][y+1]=color;
// 				q.push({x, y+1});
// 			}

//         }
//     }
// public:
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//         int og_color = image[sr][sc];
//         bfs(image,sr,sc,color,og_color);
        
//         return image;
//     }
// };

