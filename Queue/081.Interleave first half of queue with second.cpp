#include <bits/stdc++.h> 
void interLeaveQueue(queue < int > & q) {
//     queue<int>q2;
//     int n=q.size()/2;
//     //pushing half elements into new queue    
//     for(int i=0;i<n;i++){
//         q2.push(q.front());
//         q.pop();
//     }
    
//      int m=q.size();//updated size of queue
//     for(int i=0; i<m; i++){
//        q.push(q2.front());//pusing back frm new queue to orignal queue 1 by 1
//         q2.pop();
        
//         q.push(q.front());//also pushing elents from same q at back
//         q.pop();
//     }
     stack<int> s;
    int halfSize = q.size() / 2;
  
    // Push first half elements into the stack
    // queue:16 17 18 19 20, stack: 15(T) 14 13 12 11
    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }
  
    // enqueue back the stack elements
    // queue: 16 17 18 19 20 15 14 13 12 11
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
  
    // dequeue the first half elements of queue
    // and enqueue them back
    // queue: 15 14 13 12 11 16 17 18 19 20
    for (int i = 0; i < halfSize; i++) {
        q.push(q.front());
        q.pop();
    }
  
    // Again push the first half elements into the stack
    // queue: 16 17 18 19 20, stack: 11(T) 12 13 14 15
    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }
  
    // interleave the elements of queue and stack
    // queue: 11 16 12 17 13 18 14 19 15 20
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}
