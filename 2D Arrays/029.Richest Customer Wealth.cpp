class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int row=accounts.size(); int col = accounts[0].size();
        int res=0;
        for(int i=0;i<row;i++){
            int temp=0;// contains sum of  row
            for(int j=0;j<col;j++){
                temp+=accounts[i][j];// 
            }
            res= max(res,temp);//max sum of all rows
        }
        return res;
    }
};
