class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long,vector<long long>,greater<long long>> minHeap;
        
        // storing all in minheap
        for(long long i=0;i<n;i++){
            minHeap.push(arr[i]);
        }
        
        long long cost = 0;
        
        //now we first two elements are always smaller
        while(minHeap.size() > 1){
            long long first = minHeap.top();
            minHeap.pop();
            long long second = minHeap.top();
            minHeap.pop();
            // adding first two with cost
            cost = cost + first + second;
            //agai pushing the addition of two no. to heap
            minHeap.push(first + second);
        }
        return cost;
    }
};
