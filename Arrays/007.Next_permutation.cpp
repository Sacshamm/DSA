
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       if(nums.size()==1) return;
        
        int id1;
        //it checks for break point from right to left and store index
        //eg. {1, 2, 3, 6, 5, 4} in this case it is 3
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                id1=i;
                break;
            }
        }
        //now if it there is no such index we will reverse. the case may be for [3,2,1]... in this we wont find any break point so id1=0. By break point i mean 3<6
        if(id1<0){
            reverse(nums.begin(),nums.end());
        }
        else{
            int id2=0;
            //we will check for just greater element than our id1;
            for(int i=nums.size()-1;i>=0;i--){
                if(nums[i]>nums[id1]){
                    id2=i;
                    break;
                }
                
            }
        
     swap(nums[id1],nums[id2]);//{1, 2, 3, 6, 5, 4} to {1, 2, 4, 6, 5, 3}
     reverse(nums.begin()+id1+1,nums.end());//{1, 2, 4, 6, 5, 3} to {1, 2, 4, 3, 5 ,6}
        }
    }
};
