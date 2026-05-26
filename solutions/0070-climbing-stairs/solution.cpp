class Solution {
public:
    int climbStairs(int n) {
        int prev=2;
        int prev1=1;
        int curr=0;
        if(n==1)return 1;
        if(n==2)return 2;
        for(int i=3;i<=n;i++){
            curr=prev+prev1;
            prev1=prev;
            prev=curr;
        }
        return curr;
    }
};
