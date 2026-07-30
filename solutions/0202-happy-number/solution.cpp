class Solution {
public:
    bool isHappy(int n) {
        int slow=getNextNum(n);
        int fast=getNextNum(getNextNum(n));
        while(slow!=fast){
            if(fast==1)return true;
            slow=getNextNum(slow);
            fast=getNextNum(getNextNum(fast));
        }
        return slow==1;
    }
    int getNextNum(int n){
        int output=0;
        while(n>0){
            int digit=n%10;
            output+=digit*digit;
            n=n/10;
        }
        return output;
    }
};
