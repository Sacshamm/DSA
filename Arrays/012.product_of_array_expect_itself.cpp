class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //TLE O(N^2) & O(1)
        //  vector <int> ans (nums.size(),1);
        // for(int i=0;i<nums.size();i++){
        //     for(int j=0;j<nums.size();j++){
        //         if(i==j) continue;
        //         ans[i]=nums[j]*ans[i];
        //     }
        // }
        // return ans;
        vector <int>lp(nums.size());
        vector <int>rp(nums.size());
        vector <int>ans(nums.size());
        
        lp[0]=1;
        for(int i=1;i<nums.size();i++){
            lp[i]=lp[i-1]*nums[i-1];
        }
        //[1,1,2,6,24]
        
        rp[nums.size()-1]=1;
        for(int i=nums.size()-2;i>=0;i--){
            rp[i]=rp[i+1]*nums[i+1];
        }
        //[24,24,12,4,1]
        
        for(int k=0;k<nums.size();k++){
            ans[k]=rp[k]*lp[k];
        }
        
     return ans;
    }
    //https://leetcode.com/problems/product-of-array-except-self/discuss/1597959/c%2B%2B-or-discussing-all-solutions-or-explaining-in-detail-with-image-or
};
