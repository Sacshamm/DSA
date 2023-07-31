#include <bits/stdc++.h> 
bool cmp(pair<int, int> a, pair<int, int> b){
    double r1=(double)a.second/a.first;
    double r2=(double)b.second/b.first;

    return r1>r2;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(),items.end(),cmp);//sort on the v/w basis in desc order

    int currWeight=0;
    double maxVal=0;
    
    for(int i=0;i<n;i++){
        int weight = items[i].first;
        double value = items[i].second;

        //if addition of new weight is in limit then add and calc value
        if(currWeight + weight <= w){
            currWeight += weight;
            maxVal = maxVal+value;
        }
        else{
            //if not in limit then fill the left over weight
            double remainingWeight = w - currWeight;//calc how much weight left
            maxVal += (value/(double)weight) * (double)remainingWeight;// v/w * rem ... 120/30 * 20 = 80
            break;
        }
    }
    return maxVal;
}
