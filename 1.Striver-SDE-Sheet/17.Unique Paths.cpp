class Solution {
public:
    int findPaths(int r, int c, int m, int n, vector<vector<int>>&dp){
        //checking boundary conditions
        if(r>=m || c>=n) return 0;
        if(r==m-1 && c==n-1) return 1;
        //checking if already visited
        if(dp[r][c]!=-1) return dp[r][c];

        int right = findPaths(r,c+1,m,n,dp);
        int down = findPaths(r+1,c,m,n,dp);
        //storing in dp to avoid sam future calls
        return dp[r][c] = right + down;
   
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return findPaths(0,0,m,n,dp);
    }
};
