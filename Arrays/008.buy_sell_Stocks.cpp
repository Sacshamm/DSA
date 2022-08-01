// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int mini=INT_MAX;
//         int maxi=INT_MIN;
//         int count=0;
//         for(int i=0;i<prices.size();i++){
//             if(prices[i]>prices[i+1]){
//                 count++;
//             }
//             mini= min(prices[i],mini);  
//         }
        
//         for(int i=mini;i<prices.size();i++){
//             maxi=max(prices[i],maxi);
//         }
//         if(count==prices.size()) return 0;
//         return maxi-mini;
//     }
// };
class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int n= prices.size();
        int maxprofit = 0;
        int minvalue = INT_MAX;
        for(int i =0;i<n;i++){
            minvalue = min(prices[i],minvalue);
            maxprofit= max(maxprofit,prices[i] - minvalue);
        }
        return maxprofit;
    }
};
