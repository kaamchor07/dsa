class Solution {
public:
    int countGoodNumbers(long long n) {
        if(n%2==0){
            return myPow(20,n/2);
        }
        return (myPow(20,n/2)*5)%1000000007;
    }
private:
    long long myPow(long long x, long long n) {
        return helper(x,n);
    }
    long long helper(long long x,long long n){
        if(n==0) return 1;
        if(n%2==0){
            long long temp=helper(x,n/2)%1000000007;
            return (temp*temp)%1000000007;
        }else{
            long long temp=helper(x,n/2)%1000000007;
            return ((((x*temp)%1000000007)*temp)%1000000007);
        }
    }
};

