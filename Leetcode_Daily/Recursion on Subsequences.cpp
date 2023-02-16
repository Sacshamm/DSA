
// 1. for printing all the subsequences having sum = k
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printS(int index, vector<int> &v, int arr[], int n, int sum, int k){
    if(index == n){
        if(sum == k){
            for(auto it:v) cout << it << " ";
                cout << endl;
        }
        return;
    }
  //take
    v.push_back(arr[index]);
    sum += arr[index];
    printS(index + 1, v, arr, n, sum, k);
  
  //not take
    sum -= arr[index];
    v.pop_back();
    printS(index + 1, v, arr, n, sum, k);
}

    int main()
{
    int arr[] = {1,2,1};
    int n = 3;
    int k = 2;
    vector<int> v;
    printS(0, v, arr, n, 0, k);
    return 0;
}




// 2.for prinitng any 1 subsequence having sum = k
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool printS(int index, vector<int> &v, int arr[], int n, int sum, int k){
    if(index == n){
        if(sum == k){
            for(auto it:v) cout << it << " ";
                cout << endl;
        return true;
        }
        else
        return false;
    }
    v.push_back(arr[index]);
    sum += arr[index];
    if( printS(index + 1, v, arr, n, sum, k)== true)
        return true;

    sum -= arr[index];
    v.pop_back();
    if( printS(index + 1, v, arr, n, sum, k) == true)
        return true;
    return false;
}

    int main()
{
    int arr[] = {1,2,1};
    int n = 3;
    int k = 2;
    vector<int> v;
    printS(0, v, arr, n, 0, k);
    return 0;
}



// 3. Count total no. of subsequence having sum = k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int printS(int index, vector<int> &v, int arr[], int n, int sum, int k){
    if(index == n){
        if(sum == k){
            return 1;
        }
        else
        return 0;
    }

    sum += arr[index];
    int l = printS(index + 1, v, arr, n, sum, k);
 

    sum -= arr[index];
    int r = printS(index + 1, v, arr, n, sum, k);

    return l + r;
}

    int main()
{
    int arr[] = {1,2,1};
    int n = 3;
    int k = 2;
    vector<int> v;
    cout<<printS(0, v, arr, n, 0, k);
    return 0;
}
