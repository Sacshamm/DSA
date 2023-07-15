class Solution {
public:
////brute force
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     int row = 0; int col = matrix[0].size()-1;

    //     while(row<matrix.size() && col>=0){
    //         if(matrix[row][col] == target) return true;

    //         else if(target < matrix[row][col]) col--;

    //         else row++;
    //     }
    //     return false;
    // }


     bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()) return false;
        int n = matrix.size();
        int m = matrix[0].size();
        int lo = 0;
        int hi = (n * m) - 1;
        
        while(lo <= hi) {
            int mid = (lo + (hi - lo) / 2);
            if(matrix[mid/m][mid % m] == target) {
                return true;
            }
            if(matrix[mid/m][mid % m] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return false;
     }
};
