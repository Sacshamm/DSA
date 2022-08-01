class Solution {
public:
    int trap(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int leftmax=0;
        int rightmax=0;
        int result=0;
/*Algorithm:

Initialise two pointer left = 0 and right = N – 1 and res = 0.
Initialise two variables left_max = 0 and right_max = 0, denoting the maximum height on the left and maximum height on the right.
Traverse the array, i.e. while(left <= right)
If A[left] < A[right] and left_max > A[left]
Then, add left_max – A[left] to res
Else if left_max < A[left]
Update left_max to A[left]
Increment left pointer
Similarly, if If A[left] > A[right] and right_max > A[right]
Then, add right_max – A[right] to res
Else if right_max < A[right]
Update right_max to A[right]
Increment right pointer
Print res */
        
        while(left<=right){
            if(height[left] <= height[right]){
                if(height[left]>=leftmax) 
                    leftmax=height[left];
                else 
                    result+= leftmax-height[left];
                left++;
            } 
            else{
                if(height[right]>=rightmax) 
                    rightmax=height[right];
                else 
                    result+= rightmax-height[right];
                right--;
            }
        }
        return result;
    }
};
