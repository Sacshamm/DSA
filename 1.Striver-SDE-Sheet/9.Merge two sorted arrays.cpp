class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int firstArr = m-1;
        int secondArr = n-1;
        int merge = (m+n)-1;

        //comapre last index of both arrays and insert into first array according to that
        while(firstArr>=0 && secondArr>=0){
            //if n1 is smaller then insert n1 from last
            if(nums1[firstArr]<nums2[secondArr]){
                nums1[merge] = nums2[secondArr];
                merge--; secondArr--;
            }
            else{
                //otherwise insert n2
                nums1[merge] = nums1[firstArr];
                merge--; firstArr--;
            }
        }

        while(secondArr >= 0){
            nums1[merge] = nums2[secondArr];
            merge--; secondArr--;
        }

    }
};
