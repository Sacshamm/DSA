class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long power = n;
        //making pow postive
        if(power<0) power = -1*power;

        while(power){
            ////if odd then store into ans and proceed for even part
            if(power%2==1){
                ans = ans*x;
                power = power-1;
            }
            else{
                x = x*x;
                power = power/2;
            }
        }
        //handeling negative power
        if(n<0) ans = (double)1.0/double(ans);

        return ans;
    }
};

////brute force

// class Solution {
// public:
//     double calcPow(double x, int n){
//         if(x==1) return x;
//         long double pow = 1.0;
//         while(n>0){
//                 pow = pow*x;
//                 n--;
//             }
//         return pow;
//     }

//     double myPow(double x, int n) {
//        if(n<0){
//             return 1/calcPow(x,abs(n));    
//        }
//         return calcPow(x,n);
//     }
// };
