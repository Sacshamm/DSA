class Solution {
public:
    void moveZeroes(vector<int>& nums) {
//         int back=0;
//         int front=back+1;
        
//        while(front<nums.size()){
//            if(nums[front]!=0){
//                swap(nums[front],nums[back]);
//               // nums[front++]=nums[back--];
//                front++;back++;
//            }
//            else if(nums[front]==0){
//                front++;
//            }
//        }
        
        
         int start=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i],nums[start]);
                    start++;
            }
        }
    }
};

