class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index=-1;

        //find break point(smaller element than i+1) from right side 
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index=i;
                break;
            }
        }

        //if no break point it means it is sorted
        if(index==-1){
            reverse(nums.begin(),nums.end());
        }
        //break point found
        else{
            //find element just greater than that index(break point element)
            //swap it
            for(int i=n-1;i>index;i--){
                if(nums[i]>nums[index]){
                    swap(nums[i],nums[index]);
                    break;
                }
            }
            //reverse the remeaining portion
        reverse(nums.begin()+index+1,nums.end());
        }

    }
};
