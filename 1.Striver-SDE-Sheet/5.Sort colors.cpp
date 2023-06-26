// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int zero=0;
//         int one=0;
//         int two=0;

//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==0) zero++;
//             if(nums[i]==1) one++;
//             else two++;
//         }

//         int k=0;
//         for(int i=0;i<zero;i++){
//             nums[k++]=0;
//         }
//         for(int i=0;i<one;i++){
//             nums[k++]=1;
//         }
//         for(int i=0;i<two;i++){
//             nums[k++]=2;
//         }
//     }
// };



class Solution {
public:
    void sortColors(vector<int>& nums) {

        int i=0,zeros=0,twos=nums.size()-1;

        while(i<=twos){
            //taking zeros to left
            if(nums[i]==0){
                swap(nums[i],nums[zeros]);
                i++;zeros++;
            }
            //taking twos to right
            else if(nums[i]==2){
                swap(nums[i],nums[twos]);
                twos--;
            }
            else i++;
        }
    }
};
