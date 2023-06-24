class Solution {
public:
    int findNcR(int n, int r){
        long long res = 1;
        for(int i=0;i<r;i++){
            res = res*(n-i);
            res = res/(i+1);
        }
        return res;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int row=1;row<=numRows;row++){
            vector<int>temp;
            for(int col=1;col<=row;col++){
                temp.push_back(findNcR(row-1,col-1));
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
