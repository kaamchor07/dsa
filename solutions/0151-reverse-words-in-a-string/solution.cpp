class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int n=s.size();
        bool flag=false;
        string temp="";
        int i=0;
        int j=n-1;
        while(s[i]==' '){
            i++;
        }
        while(s[j]==' '){
            j--;
        }
        while(i!=j+1){
            if(s[i]==' '){
                if(s[i+1]==' '){
                    i++;
                    continue;
                }
                if(ans==""){
                    ans=temp;
                    temp="";
                    i++;
                }else{
                    ans=temp+' '+ans;
                    temp="";
                    i++;
                }
            }else{
                temp+=s[i];
                i++;
            }
        }
        if(ans==""){
            ans=temp;
        }else{
            ans=temp+' '+ans;
        }
        return ans;
    }
};
