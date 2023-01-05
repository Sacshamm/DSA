// 1) We will sort on the basis of starting time of the array.
//    Because after doing this we can surely say that the intervals that start first will appear first.
// 2) Our main motive here is to carry out an active set,
//    to check with only one arrow how many balloons we are able to burst.
// 3) Now, what is an active set, active set is nothing but the common area between two comparing sets.
// 4) See the dry run also for further clarity.


// 1) Suppose array given to us as: arr = [[10,16],[2,8],[1,6],[7,12]]
// 2) After sorting, it looks like:
//      [[1,6]
//      [2,8],
//      [7,12],
//      [10,16]]
	 
// 3) Initially if the size of the array is greater or equal to one,
// then we can say that at least we are required a single arrow, so initially arrow count will be 1, i.e arrow = 1;

// 4) Also, initially we provide start to the starting point of zero index of array, i.e start = arr[0][0] = 1
// and end as ending point of zero index i.e end = arr[0][1] = 6

// 5) Now, we run a loop from 1 to n (n being the size of array)
//    and then update our active set on the basis of conditions.

// 6) So we start the loop from i = 1, 
//          [[1,6]
//     --> [2,8],   Now, we will see the active set b/w [1,6] and [2,8] is [2,6]
//         [7,12],
//         [10,16]]

// Our old active set i.e [start, end] is [1,6] 
// Now, it overlaps with current interval i.e i = 1, arr[1] = [2,8]
// so we will recreate our new active set and that will be [2,6]

// So, how we achieve this active set,
// start = max(start, arr[i][0]); --> max(1, 2) --> 2
// and end = min(end, arr[i][1]); --> min(6, 8) --> 6

// 7) now, arrow = 1, start = 2 and end = 6 
// now moving ahead for i = 2
//        [[1,6],
//         [2,8],   
//   --> [7,12],  Now, we will see the active set b/w [2,6] and [7,12] is [] i.e nothing
//         [10,16]]

// Our old active set i.e [start, end] is [2,6] 
// Now it does not overlap with current interval i.e i = 2, arr[2] = [7, 12]

// So, we will require another arrow to burst this  active set and 
//     hence increment arrow i.e arrow++, now arrow will become 2.
	
// Also we have to recreate our whole active set again, therefore:
//  start = arr[i][0] = arr[2][0] = 7
//  end = arr[i][1] = arr[2][1] = 12
 
// 8) now, arrow = 2, start= 7 and end = 12
// now moving head for i = 3
//       [[1,6],
//       [2,8],   
//       [7,12], 
// --> [10,16]] Now, we will see the active set b/w [7,12] and [10,16] is [10,12]

// So, they overlap and does not require any another arrow
// Now, loop will be over and arrow required will be 2 in this case.


class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        int n = points.size();
        sort(points.begin(),points.end());
        int c=1;
        int start = points[0][0];
        int end = points[0][1];
        for(int i=1;i<n;i++){
           if(points[i][0] > end){
               c++;
               start = points[i][0];
               end = points[i][1];
           }
           else{
               start = max(start,points[i][0]);
               end = min(end,points[i][1]);
           }
        }
        return c;
    }
};
