//brute
class Solution {
public:
    //marking non zero rows
    void markR(int i, int m, vector<vector<int>>& matrix){
        for(int c=0;c<m;c++){
            if(matrix[i][c]!=0){
                matrix[i][c]=-10;
            }
        }
    }
    //marking non zero cols
    void markC(int j, int n, vector<vector<int>>& matrix){
        for(int r=0;r<n;r++){
            if(matrix[r][j]!=0){
                matrix[r][j]=-10;
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        //search for 0 and mark them
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    markR(i,m,matrix);
                    markC(j,n,matrix);
                }
            }
        }
        //mark those previously marked non zero with zero
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==-10){
                    matrix[i][j]=0;
                }
            }
        }
    }
};

//better

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
         int n=matrix.size();
         int m=matrix[0].size();

         //keep a record of rows and cols in additional array having 0 and mark them
         vector<int>row(n,0);
         vector<int>col(m,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(row[i]==1 || col[j]==1){
                    matrix[i][j]=0;
                }
            }
        }
    }
};



