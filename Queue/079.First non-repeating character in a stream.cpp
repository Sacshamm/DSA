//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
	public:
		string FirstNonRepeating(string A){
		    unordered_map<char,int>count;
		    queue<int>q;
		    string ans="";
		    
		    //to store the count of each character
		    for(int i=0;i<A.length();i++){
		        char ch=A[i];
		        count[ch]++;
		        
		        //also push that char into queue
		        q.push(ch);
		    
		  //checking in queue
		  while(!q.empty()){
		      if(count[q.front()]>1){//if it is repeating the  pop;
		          q.pop();
		      }
		      else{
		          ans.push_back(q.front());//if not then push that element into ans and break
		          break;
		      }
		  }
		  if(q.empty()) ans.push_back('#');// if repeating then push '#' in ans
		}
		  return ans;
	}

};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
