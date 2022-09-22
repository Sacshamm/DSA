#include <iostream>
using namespace std;
//int main(){
  //insertion ka
//     int arr[10],n,i;
//     cin>>n;
//     for( i=0;i<n;i++){
//         cin>>arr[i];
//      }
//      int pos,value;
//      cin>>pos>>value;
//      for( i=n-1;i>=pos-1;i--){
//        arr[i+1]=arr[i];
//      }
//      arr[pos-1]=value;
//      n++;
//      for(i=0;i<n+1;i++){
//      cout<<arr[i];
//      }
// }
// or simply u can do in an unsorted array 
// a[n]=a[pos-1]
// a[pos-1]=num

//deletion ka
int main(){
  int arr[10],size,pos,i;
    cin>>size;
    for( i=0;i<size;i++){
        cin>>arr[i];
     }
    //    cin>>pos;
    //  if(pos<=0||pos>size)
    //  cout<<"invalid pos";
    //  else{
    //    for(i=pos-1;i<size-1;i++){
    //      arr[i]=arr[i+1];
    //    }
    //    size--;
    //  }
    //  for(i=0;i<size;i++){
    //  cout<<arr[i];
    //  }
    cout<<arr[2];
    cout<<2[arr];
    cout<<*(arr+2)<<*arr+2;
     return 0;
}
//if u want to del from last size--
//simple me u cn write a a[pos-1]=a[size-1] and then size