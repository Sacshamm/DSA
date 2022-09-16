class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
//         //brute force
//         int maxArea = 0;
//         int n = heights.size();
//         for(int i = 0; i < n; i++)
//         {
//             int left_smaller = i, right_smaller = i;
            
//             while(left_smaller-1 >= 0 && heights[left_smaller-1] >= heights[i])
//                 left_smaller--;
            
//             while(right_smaller+1 < n && heights[right_smaller+1] >= heights[i])
//                 right_smaller++;
            
//             maxArea = max(maxArea, (right_smaller-left_smaller+1) * heights[i]);
//         }
//         return maxArea;
        
        
        int maxArea = 0;
        int n = heights.size();
        int left[n], right[n];
        stack<int>st;
        
        // searching for left smaller element than i
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>= heights[i]) {
                st.pop();
            }
            
              if(st.empty()) left[i]=0;
              else left[i]=st.top()+1;
            st.push(i);
        }
        
        //making stack empty to get reused
        while(!st.empty()) st.pop();
        
        // searching for right smaller element than i
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            
              if(st.empty()) right[i]=n-1;
              else right[i]=st.top()-1;
            st.push(i);
        }
        
        for(int i=0;i<n;i++){
            maxArea= max(maxArea , (right[i]-left[i]+1)*heights[i]);
        }
        return maxArea;
    }
};
