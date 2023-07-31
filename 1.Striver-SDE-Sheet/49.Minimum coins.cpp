vector<int> MinimumCoins(int n)
{
    vector<int> currency = {1,2,5,10,20,50,100,500,1000};
    int i=currency.size()-1;
    vector<int>ans;

    while(n>0){
        if(n - currency[i] >= 0){
            n = n - currency[i];
            ans.push_back(currency[i]);
        }
        else i--;
    }
    return ans;
}
