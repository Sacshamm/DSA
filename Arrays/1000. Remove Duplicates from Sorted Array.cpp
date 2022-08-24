class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // set<int> s;
        // for(int i=0;i<nums.size();i++){
        //     s.insert(nums[i]);
        // }
        // int ans= s.size();      
        // int i=0;
        // for(auto x:s){
        //   nums[i]=x;
        //     i++;
        // }
        // return ans;  
         
        // int n=nums.size();
        // int count=0;
        // for(int i=1;i<n;i++){
        //   if(nums[i-1]==nums[i]) count++;
        //   else{
        //       nums[i-count]=nums[i];
        //   }
        // }
        // return n-count;
        
        if(nums.size() == 0) return 0;
        int left = 0;
        for(int right =1; right< nums.size(); right++){
           if(nums[left] != nums[right])
               left++;
               nums[left] = nums[right];
           }
    return left+1;
    }  
};
