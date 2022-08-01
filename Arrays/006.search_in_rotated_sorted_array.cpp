class Solution {
public:
     int search(vector<int>& nums, int target) {
    //     for(int i=0;i<nums.size();i++){
    //         if(target==nums[i]){
    //             return i;
    //         }
    //     }
    //     return -1;
         
         int low=0; int high=nums.size()-1;
       
         
         while(low<=high){
               int mid= low+(high-low)/2;
             if(nums[mid]==target) return mid;
             
             if(nums[mid]>=nums[low]){// to check if left half is sorted
                 if(target>=nums[low] && target<=nums[mid]) high=mid-1;//means target lie in left sorted area 
                  else low=mid+1;
                  
             }
             else{
                 //right half sorted
                 if(target>=nums[mid] && target<=nums[high]) low=mid+1;//means target lie in right sorted area 
                 else high=mid-1;
             }
             
         }
         return -1;
         
     }
    
    
};
