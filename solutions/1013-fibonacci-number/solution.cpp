// class Solution {
// public:
//     int fib(int n) {

//         if(n==1){
//             return 1;
//         }else if(n==0){
//             return 0;
//         }
//         return fib(n-1) + fib(n-2);
//     }
// };
class Solution {
public:
    int fib(int n) {
        if(n<=1){
            return n;
        }
        int f=0;
        int s=1;
        for(int i=2;i<=n;i++){
            int t=f+s;
            f=s;
            s=t;
        }
        return s;
    }
};
