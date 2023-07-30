int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    int minPlatforms = 1;

    //sort both
    sort(at,at+n);
    sort(dt,dt+n);

    int a=1, d=0;
    int platforms = 1;//local count

    while(a<n && d<n){
        //if incomming train time clashing then we need new pltfrm
        if(at[a] <= dt[d]){
            platforms++;
            a++;
        }
        //if not then we can use previous pltfrms
        else{
            platforms--;
            d++;
        }
        minPlatforms = max(minPlatforms,platforms);
    }
    return minPlatforms;
}
