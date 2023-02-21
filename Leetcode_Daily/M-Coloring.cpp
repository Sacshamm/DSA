class Solution{
public:
    bool isPossible(int node,int color[],bool graph[101][101],int n, int newColor){
        for(int i=0;i<n;i++){
            if(i!=node && graph[i][node]==1 && color[i]==newColor) return false;
        }
        return true;
    }

    bool solve(int node,int color[],bool graph[101][101], int m, int n){
        if(node == n) return true;
        
        for(int i=1;i<=m;i++){
            if(isPossible(node,color,graph,n,i)==true){
                color[node] = i;
                if(solve(node+1,color,graph,m,n)==true) return true;
                color[node] = 0;
            }
        }
        return false;
    }
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int color[n] = {0};
        if(solve(0,color,graph,m,n) == true) return true;
        return false;
    }
};
