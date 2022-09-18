class Solution 
{
    private:
    bool knows(vector<vector<int> >& M, int a, int b){
        if(M[a][b]==1) return true;
        else return false;
    }
    
    public:
  
    int celebrity(vector<vector<int> >& M, int n){
        stack<int>st;
        for(int i=0;i<n;i++){//push all elements in stack eg 0,1,2
            st.push(i);
        }
        
        while(st.size()>1){
            int a=st.top(); st.pop();
            int b=st.top(); st.pop();
            
            if(knows(M,a,b)) st.push(b);//if a knows b then a is not celebrity hence neglected
            else st.push(a);//if b knows a then b is not celebrity hence neglected
        }
        
        int candidate=st.top();//single left out element in stack may or may not be a celebrity
        
        //verifying if it is celebrity or not
        
        //1)Verify whether the celebrity knows any other person.
        bool rowCheck = false;
        int zeroCount=0;
        
          for(int i=0;i<n;i++){
            if(M[candidate][i]==0) zeroCount++;
        }
        //If all rows are 0's it means it doesnt know anyone
        if(zeroCount==n) rowCheck=true;
        
        //2) Verify whether the celebrity is known to all the other person.
        bool colCheck = false;
        int oneCount=0;
        
          for(int i=0;i<n;i++){
            if(M[i][candidate]==1) oneCount++;
        }
         //If all cols are 1's except diagnol it means it  knows everyyone
        if(oneCount==n-1) colCheck=true;
        
        //if a candidate doesnt know anyone and everyone knows him then it is a celebrity
        if(rowCheck and colCheck) return candidate;
        else return -1;
    }
      
};
