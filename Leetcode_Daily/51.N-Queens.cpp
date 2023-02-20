class Solution {
public:
     void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n,  vector<int>& leftRow, vector<int>& upperD, vector<int>& lowerD){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if( leftRow[row]==0 && upperD[(n-1) + (col-row)]==0 &&
            lowerD[row+col]==0 ){
                board[row][col] = 'Q';
                leftRow[row]=1;
                upperD[(n-1)+(col-row)]=1;
                lowerD[row+col]=1;
                solve(col+1,board,ans,n,leftRow,upperD,lowerD);
                board[row][col] = '.';
                leftRow[row]=0;
                upperD[(n-1)+(col-row)]=0;
                lowerD[row+col]=0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++) board[i] = s;
        vector<int>leftRow(n,0);
        vector<int>upperD(2*n-1,0);
        vector<int>lowerD(2*n-1,0);

        solve(0,board,ans,n,leftRow,upperD,lowerD);
        return ans;
    }
};


////quite easy but taking O(n) for checking if 'Q' present in previous row or col 
// class Solution {
// public:
//     bool isSafe(int row, int col, vector<string>& board , int n){
//         int dupRow = row;
//         int dupCol = col;
//         //left upward diagnol
//         while(row>=0 && col>=0){
//             if(board[row][col] == 'Q') return false;
//             row--; col--;
//         }

//         row = dupRow;
//         col = dupCol;
//         //left
//         while(col>=0){
//             if(board[row][col] == 'Q') return false;
//             col--;
//         }

//         row = dupRow;
//         col = dupCol;
//         //left downward diagnol
//         while(row<n && col>=0){
//             if(board[row][col] == 'Q') return false;
//             row++; col--;
//         }
//         return true;
//     }

//     void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
//         if(col == n){
//             ans.push_back(board);
//             return;
//         }

//         for(int row=0;row<n;row++){
//             if(isSafe(row, col, board, n)==true){
//                 board[row][col] = 'Q';
//                 solve(col+1,board,ans,n);
//                 board[row][col] = '.';
//             }
//         }
//     }
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;
//         vector<string>board(n);
//         string s(n,'.');
//         for(int i=0;i<n;i++) board[i] = s;

//         solve(0,board,ans,n);
//         return ans;
//     }
// };






