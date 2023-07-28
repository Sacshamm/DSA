class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int j=1;j<nums.size();j++){
            if(nums[i]!=nums[j]){//find elements which are not same as i
                nums[i+1]=nums[j];//assign i's next position to it
                i++;
            }
        }
        return i+1;
    }
};
