// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int findMinOps(int arr[], int n){
    int ans=0;
    int l=0;
    int r=n-1;
     while(l<=r){
         if(arr[l]==arr[r]){
             r--;l++;
         }
         else if(arr[l]>arr[r]){
             r--;
             arr[r]+=arr[r+1];
             ans++;
         }
         else{
             l++;
             arr[l]+=arr[l-1];
             ans++;
         }
     }
     return ans;
}

int main()
{
    int arr[] = {1,  9, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Count of minimum operations is "
         <<  findMinOps(arr, n) << endl;
    return 0;
}
