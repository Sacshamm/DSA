class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1=0,cnt2=0;
        int ele1,ele2;

        for(int i=0;i<n;i++){
            //ensure that elements do not interchange
            if(cnt1==0 && nums[i]!=ele2){
                cnt1=1;
                ele1=nums[i];
            }
            else if(cnt2==0 && nums[i]!=ele1){
                cnt2=1;
                ele2=nums[i];
            }
            else if(nums[i]==ele1) cnt1++;
            else if(nums[i]==ele2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1=0; cnt2=0;
        vector<int>v;
        int mini = int(n/3)+1;

        for(int i=0;i<n;i++){
            if(ele1==nums[i]) cnt1++;
            if(ele2==nums[i]) cnt2++;
        }
        if(cnt1>=mini) v.push_back(ele1);
        if(cnt2>=mini) v.push_back(ele2);

        return v;
    }
};



// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         vector<int>v;
//         unordered_map<int,int> mp;
//         //take floor value 
//         int mini = int(n/3)+1;

//         for(int i=0;i<n;i++){
//             mp[nums[i]]++;
//             //if at any time freq. in map == minimum occurence then add in list
//             if(mp[nums[i]]==mini) v.push_back(nums[i]);

//             if(v.size()==2) break;
//         }
//         return v;
//     }
// };
