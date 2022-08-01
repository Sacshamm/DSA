class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        // int  mini=nums[0];
        // for(int i=0;i<nums.size();i++){
        //     mini=min(nums[i],mini);
        // }
        // return mini;
        int low=0;
        int high=n-1;
        int mid;
        
        while(low<high){
          mid=low+(high-low)/2;
          if(nums[low]<=nums[mid] && nums[low]>nums[high])
              low=mid+1;
          else
              high=mid;
        }
        return nums[low];
    }
};
