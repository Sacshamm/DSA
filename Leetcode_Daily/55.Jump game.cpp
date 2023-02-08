//start from last index and check if the last_index-1+ nums[last_index-1] >= lastindex
//if yes then update to that index
//if not then keep last index same

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        int n = nums.size()-1;
        int lastpos=n;

        for(int i=n-1;i>=0;i--){
            if(i+nums[i]>=lastpos) lastpos = i;
        }
        if(lastpos == 0) return true;
        return false;
    }
};




// if(nums.size()==1) return true;
//         int maxi = nums[0];
//         int i=0;
//         while(maxi--){    
//             maxi = max(nums[i],maxi);
//             if(i==nums.size()) return true;
//             i++;
//         }
//         return false;
