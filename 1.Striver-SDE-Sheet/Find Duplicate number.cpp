class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int start = nums[0];
        int fast = nums[0];

        do{
            start = nums[start];
            fast = nums[nums[fast]];
        }while(start!=fast);

        fast = nums[0];
        while(start!=fast){
            start = nums[start];
            fast = nums[fast];
        }
        return fast;
    }
};


// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int x = 0;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==nums[i+1]){
//                 x =  nums[i];
//                 break;
//             }
//         }
//         return x;
//     }
// };
