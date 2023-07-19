// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int left=0;
//         int right=1;
//         int n=nums.size();
//         int maxLen=0;
//         int sum=nums[0];
//         // sliding window approach 
//         while(right<n){
//             // both dont cross and if sum is greater then reduce left
//             while(left<=right && sum>k){
//                 sum-=nums[left];
//                 left++;
//             }
//             //if subarray found then update length
//             if(sum == k) maxLen = max(maxLen,right-left);

//             // increment to add more while still in boundary
//             if(right<n) sum+=nums[right];
//             right++;
//         }
//         return maxLen;
//     }
// };




















class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        // int n = arr.size(); // taking the size of the array 
        // int ans = 0; // ans variable to store our count 
        // for(int i = 0; i < n; i++) // traverse from the array
        // {
        //     int sum = arr[i]; // provide sum with arr[i]   
        //     if(sum == k) // if element itself equal to k, then also increment count
        //         ans++;  
        //     for(int j = i + 1; j < n; j++) // now moving forward,
        //     {
        //         sum += arr[j]; // add elements with sum      
        //         if(sum == k) // if at any point they become equal to k
        //             ans++; // increment answer
        //     }    
        // }
        // return ans; // and at last, return answer
    
        unordered_map<int,int> map; 
        int sum = 0, result = 0;
        map[sum] = 1;
        
        for (int n : arr) {
            sum += n;
            result += map[sum - k];
            map[sum]++;
        }
        return result;
       }
    };
