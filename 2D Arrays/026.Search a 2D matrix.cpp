class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int total=row*col;
        
        int start=0;
        int end=total-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            int ele= matrix[mid/col][mid%col];
            
            if(ele>target) end=mid-1;
            else if(ele<target)start=mid+1;
            else return true;
        }
        return false;
    }
};
