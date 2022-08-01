class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //O(nlogn)
    //     sort(nums.begin(),nums.end());
    //     reverse(nums.begin(),nums.end());
    //     return nums[k-1];
    
        //O(klogk) & space O(n)  for  max heap
  //   priority_queue<int> pq;
  //   for(int i=0;i<nums.size();i++){
  //       pq.push(nums[i]);
  //   }
  //   int neglect=k-1;
  //   while(neglect){
  //       pq.pop();
  //       neglect--;
  //   }
  //   return pq.top();
  
    // O(klogk) bt space O(k)  for min heap
     priority_queue<int, vector<int>, greater<int>> minpq;
    for(int i=0;i<nums.size();i++){
        if(minpq.size()<k)
        minpq.push(nums[i]);
        else{
            if(minpq.top()<nums[i]){
                minpq.pop();
                minpq.push(nums[i]);
            }
        }
    }
        return minpq.top();
  }
};
