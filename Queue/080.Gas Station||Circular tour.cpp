class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       int n=gas.size();
//       int deficit=0;
//       int balance=0;
//       int start=0;
      
//       for(int i=0;i<n;i++){
//           balance=balance+(gas[i]-cost[i]);
//           if(balance<0){
//               deficit+=balance;
//               start=i+1;
//               balance=0;
//           }
//       }
//       if(deficit+balance>=0) return start;
//       else return -1;
//     }
        
    int total_petrol=0;
    int total_distance=0;
    
    //sum up petrol and distance
     for(int i=0;i<n;i++){
        total_petrol+=gas[i];
        total_distance+=cost[i];
     }
    
    //if petrol is less than distance
    if(total_petrol<total_distance) return-1;
    
    int balance=0;
    int start=0;
    //calculate balance 
    for(int i=0;i<n;i++){
        if(balance<0){// if bal is -ve it means it cannot move further
            start=i;//so place start at i
            balance=0;//update balance 
        }
         balance+=gas[i]-cost[i];//balance calculation
    }
   return start;
   }
};
