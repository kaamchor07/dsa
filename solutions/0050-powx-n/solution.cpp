class Solution {
public:
    double myPow(double x, int n) {
        long long N=n;
        if(N<0){
            N=N*-1;
            return 1.0/helper(x,N);
        }
        return helper(x,N);
    }
    double helper(double x,int n){
        if(n==0) return 1;
        if(n%2==0){
            double temp=helper(x,n/2);
            return temp*temp;
        }else{
            double temp=helper(x,n/2);
            return x*temp*temp;
        }
    }
};
