class Solution {
public:
    bool isValid(int row, int col, char c,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            //if same element found in a row then ret false
            if(board[row][i]==c) return false;

            //if same element found in a col then ret false
            if(board[i][col]==c) return false;

            //to check in 3*3 cells for this refer copy or video again
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        //search for empty cells
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                //if empty
                if(board[i][j] == '.'){
                    //run a loop and try all possible values frm 1 to 9
                    for(char c='1';c<='9';c++){
                        
                        if(isValid(i,j,c,board)==true){
                            //if valid then add that value 
                             board[i][j] = c;
            
                        //recursive call to check all posibilities for other empty cells
                        if(solve(board)==true) return true;
                        //if not true then remove added element and backtrack
                        else board[i][j] = '.';
                        } 
                    }
                //if empty cells are there and sudoku cant be solved using given values, ret false
                    return false;
                }
            }  
        }
        //if no empty cells then simply return true
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
