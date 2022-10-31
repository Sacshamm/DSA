class Solution {
public:
typedef pair<int,int> p;//making pair to store element and its index in pq
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        if(nums.size()==k) return nums;
        
        //pushing first k elements into minH along with indexes
        priority_queue<p,vector<p>,greater<p>>q;
            for(int i=0;i<nums.size();i++){
                q.push({nums[i],i});
                //basicllay to fill only K max elemnets
                if(q.size()>k){
                    q.pop();
                }
            }
           // another  min heap to store accoring to the index(sorted order) 
         priority_queue<p,vector<p>,greater<p>>aux;
            while(!q.empty()){
                aux.push({q.top().second,q.top().first});
                q.pop();
            }
        
        // once the elements are sorted according to their indices , push them in a vector
        vector<int>ans;
            while(!aux.empty()){
                ans.push_back(aux.top().second);
                aux.pop();
            }
        
        // finally return the answer
        return ans;
    }
};



//  //test cases failed bcz of not maintaining index's order

//  vector<int> maxSubsequence(vector<int>& nums, int k) {
//         if(nums.size()==k) return nums;
//         priority_queue<int,vector<int>,greater<int>>pq;
//   //pushing first k max elements
//         for(int i=0;i<k;i++){
//             pq.push(nums[i]);
//         }

//         for(int i=k;i<nums.size();i++){
//             if(pq.top()<nums[i]){
//                 pq.pop();
//                 pq.push(nums[i]);
//             }
//         }
   /*pushing that max K elemnts into vector and returing bcz sum of the k elements left
        in minHeap is always maximum*/
//         vector<int>v;
//         while(k--){
//             int n = pq.top();
//             pq.pop();
//             v.push_back(n);
//         }
//      return v;
