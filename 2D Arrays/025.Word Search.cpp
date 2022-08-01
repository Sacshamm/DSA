class Solution {
public:
    
bool search(int row,int col,int i,int j,vector<vector<char>>& board,string word,int k){
    //corner cases
    if(k==word.size()) return true;
    if(i<0 || j<0 || i==row || j==col || board[i][j]!=word[k]) return false;
    //to prevent repeating of cell
    char ch = board[i][j];
    board[i][j]='#';
    
    bool op1 =search(row,col,i+1,j,board,word,k+1);//down
    bool op2 =search(row,col,i-1,j,board,word,k+1);//up
    bool op3 =search(row,col,i,j+1,board,word,k+1);//right
    bool op4 =search(row,col,i,j-1,board,word,k+1);//left
    //reassignig
    board[i][j]=ch;
    
    return op1||op2||op3||op4;
}
    
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==word[0]){//starting search with first index(char) 
                    if(search(row,col,i,j,board,word,0)) return true;
                }
            }
        }
        return false;
    }
};
//TC = O(n*m*4^k)... where k is size of word
//which is huge
