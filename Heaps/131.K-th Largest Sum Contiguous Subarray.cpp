class Solution{
public:
    int kthLargest(vector<int> &arr,int n,int k){
        
    priority_queue<int,vector<int>,greater<int>>pq;//minHeap
    
    //calculating sum of every subarry present there
        for(int i=0;i<n;i++){
          int sub_sum=0;
               for(int j=i;j<n;j++){
                  sub_sum+=arr[j];
                
                //pushing first k elements
                  if(pq.size() < k){
                    pq.push(sub_sum);
                }
                else{
                    //if any sub_sum found greater then pushing into pq
                    if(sub_sum > pq.top()){
                        pq.pop();
                        pq.push(sub_sum);
                    }
                      
                }
            }
        }
        //top of pq is having the Kth max subarray sum
        return pq.top();
        
    }
};
