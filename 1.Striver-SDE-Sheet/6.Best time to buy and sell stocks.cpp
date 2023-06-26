class Solution {
public:
    int maxProfit(vector<int>& a) {
        int mini=a[0];
        int maxi = 0;

        for(int i=1;i<a.size();i++){
            mini = min(mini,a[i]);
            maxi = max(maxi,a[i]-mini);
        }
        return maxi;
    }
};


// [2,4,1] test case failed
//ans 2 hai but 0 de rha hai

// class Solution {
// public:
//     int maxProfit(vector<int>& a) {
//       int mini = a[0];
//       int index=0;
//       for(int i=0;i<a.size();i++){
//           if(a[i]<mini){
//               mini = a[i];
//               index = i;
//           }
//       }

//       if(index == a.size()) return 0;

//       int maxi = -1;
//       for(int i=index;i<a.size();i++){
//           maxi = max(maxi,a[i]);
//       }

//       return maxi-mini;
//     }
// };


