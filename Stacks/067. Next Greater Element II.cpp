class Solution {
  public:
    vector < int > nextGreaterElements(vector < int > & nums) {
      int n = nums.size();
      vector < int > nge(n, -1);
      stack < int > st;
      for (int i = 2 * n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i % n]) {
          st.pop();
        }

        if (i < n) {
          if (!st.empty()) nge[i] = st.top();
        }
        st.push(nums[i % n]);
      }
      return nge;
    }
};




class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
    //circular integer array -> when we consider first element as the next of the last element hence it's circular 
        
        vector<int> ans(nums.size(), -1); // to store the next greater element of every element and initialize it with -1 why ? because if there is no element in stack which is greater to the element we will return -1
        
        stack<int> s; //make a stack 
        
        for(int i = 0; i < 2*nums.size()-1; i++) { //why ? 2*nums.size()-1 beacuse we assuming a joint imaginary array same as nums
            
            while(!s.empty() && nums[s.top()] < nums[i%nums.size()]) {
                //check  if the stack is not empty  and the check the top element of the stack if there is an element present which is smaller than i% nums.size
                ans[s.top()] = nums[i%nums.size()];
                s.pop();// pop the elements which are smaller 
            }
            s.push(i%nums.size()); 
        }
        return ans;
    }
};
