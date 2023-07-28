class Solution {
public:
    int trap(vector<int>& a) {
        int  n = a.size();
        int l=0;
        int r=n-1;
        int rmax=0;
        int lmax=0;
        int water=0;

        while(l<=r){
            if(a[l]<=a[r]){
                if(lmax<=a[l]) lmax=a[l];
                else water+=lmax - a[l];
            l++;
            }
            else{
                if(rmax<=a[r]) rmax=a[r];
                else water+=rmax - a[r];
            r--;
            }
        }
        return water;
    }
};



/////TLE
// class Solution {
// public:
//     int trap(vector<int>& a) {
//         int n = a.size();
//         int sum=0;

//         for(int i=0;i<n;i++){
//             int j=i;
//             int leftmax=0, rightmax=0;
//             //find left max from i
//             while(j>=0){
//                 leftmax = max(leftmax,a[j]);
//                 j--;
//             }

//             //find right pos from i
//             j=i;
//             while(j<n){
//                 rightmax = max(rightmax,a[j]);
//                 j++;
//             }

//             //sum will be the min of them - and curr pos
//             sum += min(leftmax,rightmax) - a[i];
//         }
//         return sum;
//     }
// };
