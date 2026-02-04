class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        int c=0;
        bool flag=false;
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                c++;
            }else{
                c--;
            }
            if(c==1 && flag==false){
                flag=true;
            }else if(c==0){
                flag=false;              
            }else{
                ans+=s[i];
            }
        }
        return ans;
    }
};
