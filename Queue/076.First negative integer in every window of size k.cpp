vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    
    queue<int> qu;
    
    // Insert all negative numbers in queue from first window of K numbers
    for(int i = 0; i < K; i++){
        if(A[i] < 0){
            qu.push(A[i]);
        }
    }
    
    vector<long long> ans;
    
// If no negative number is there in first window of size k, push 0 to answer else push the first negative number present in queue
    
    if(qu.empty()) ans.push_back(0);
    else ans.push_back(qu.front());
    
// Start iterating from next possible window and insert negative numbers if find.
  
    for(int i = K; i < N; i++){
        
// inserting negative number in queue if found
        
        if(A[i] < 0) 
        	qu.push(A[i]);
        
// if the first element of previous window is negative pop it bcz it is now out of the current window
        
        if(A[i-K] < 0)
            qu.pop();
            
// If no negative number is there in current window, push 0 to answer else push the first negative number present in queue
        
        if(qu.empty()) 
        	ans.push_back(0);
        else 
        	ans.push_back(qu.front());
    }
    
    return ans;
    
    
 }
