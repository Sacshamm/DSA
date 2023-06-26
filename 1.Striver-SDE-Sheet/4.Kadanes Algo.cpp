// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int sum=0;
//         int ans=INT_MIN;
//         for(int i=0;i<nums.size();i++){
//            sum=max(sum+nums[i],nums[i]);
//             ans=max(sum,ans);
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;

        //calculate running sum and update to maxi
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxi = max(sum,maxi);

            //if at any point sum is in negative resetit to 0
            if(sum<0) sum=0;
        }
        return maxi;
    }
};
