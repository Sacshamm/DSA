bool cmp(pair<int,int>a, pair<int,int>b){
    return (a.second < b.second);
}


int maximumMeetings(vector<int> &start, vector<int> &end)
{
    vector<pair<int,int>> v;

    for(int i=0;i<end.size();i++){
        pair<int,int>p = make_pair(start[i],end[i]);
        v.push_back(p);
    }

    sort(v.begin(),v.end(),cmp);//sort on the basis of end time

    int cnt=1;
    int prevEndTime=v[0].second;//end time of last visited

    for(int i=1;i<v.size();i++){
        //if curr start time is greater than prev end time
        if(prevEndTime < v[i].first){
            cnt++;
            prevEndTime = v[i].second;
        }
    }
    return cnt;
}
