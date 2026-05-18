class Solution {
private:
    int helper(string &s,bool &flag1,int index,bool &flag2,long long &ans,int &neg){
        if(ans/10000000000 != 0){
            if(neg==1){
                return INT_MAX;
            }else{
                return INT_MIN;
            }
        }
        if(index==s.size()){
            if(ans>INT_MAX && neg==1){
                return INT_MAX;
            }else if(ans*-1 < INT_MIN){
                return INT_MIN;
            }
            return ans*neg;
        }
        if(flag1==true){
            if(s[index]==' '){
                return helper(s,flag1,index+1,flag2,ans,neg);
            }else{
                flag1=false;
                return helper(s,flag1,index,flag2,ans,neg);
            }
        }
        if(flag2==true){
            if(s[index]=='-'){
                flag2=false;
                neg=-1;
                return helper(s,flag1,index+1,flag2,ans,neg);
            }else if(s[index]=='+'){
                flag2=false;
                return helper(s,flag1,index+1,flag2,ans,neg);
            }else{
                flag2=false;
                return helper(s,flag1,index,flag2,ans,neg);
            }
        }
        if(isdigit(s[index])){
            ans*=10;
            int curr=s[index]-'0';
            ans+=curr;
            return helper(s,flag1,index+1,flag2,ans,neg);
        }else{
            if(ans>INT_MAX && neg==1){
                return INT_MAX;
            }else if(ans*-1 < INT_MIN){
                return INT_MIN;
            }
            return ans*neg;
        }
    }
public:
    int myAtoi(string s) {
        bool flag1=true;
        bool flag2=true;
        int index=0;
        long long ans=0;
        int neg=1;
        return helper(s,flag1,index,flag2,ans,neg);
    }
};
