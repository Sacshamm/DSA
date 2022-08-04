// class Solution {
// public:
//     int solve(vector<vector<int>>& matrix, int mid){
//         int count = 0, n = matrix.size(), i = n-1, j = 0;
//         while(i >= 0 && j < n){
//             if(matrix[i][j] > mid) i--;
//             else{
//                 count += (i+1);
//                 j++;
//             }
//         }
//         return count;
//     }
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         int n = matrix.size(), i = matrix[0][0], j = matrix[n-1][n-1];
//         while(i < j){
//             int mid = i + (j-i)/2;
//             int posi = solve(matrix, mid);
//             if(posi < k) i = mid+1;
//             else j = mid;
//         }
//         return i;
//     }  
// };

// class Solution {
// public:
//     //o(nlogk), O(k)
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         priority_queue<int>pq; int n = matrix.size();
//         for(int i = 0; i < n; i++)
//             for(int j = 0; j < n; j++){
//                 pq.push(matrix[i][j]);
//                 if(pq.size() > k) pq.pop();
//             }
//         return pq.top();   
//     }
// };

class Solution {
public:
    //O n(logn) ... O(1)
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n= matrix.size();
        int low=matrix[0][0]; int high=matrix[n-1][n-1];
        
        while(low<high){
            int mid=low+(high-low)/2;
            int count=0;
            for(int i=0;i<n;i++){
            count+= upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin(); 
            }
            if(count<k) low=mid+1;
            else high=mid;
        }
        return low;
      }
};
