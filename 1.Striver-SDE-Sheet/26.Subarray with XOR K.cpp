#include <bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int b) {
    int n = a.size();
    int cnt=0;
    // int xr=0;
    // map<int,int>mp;
    // mp[xr]++; //0,1

    // for(int i=0;i<n;i++){
    //     xr = xr^a[i];
    //     int x = xr^b;
    //     if(mp.find(x)!=mp.end()) cnt+=mp[x];
    //     mp[xr]++;
    // }
    // return cnt;

    //brute force below
    for(int i=0;i<n;i++){
        int xr=0;
        for(int j=i;j<n;j++){
            xr^=a[j];
            if(xr == b) cnt++;
        }
    }
    return cnt;
}
