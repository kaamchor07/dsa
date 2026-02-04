class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int count=0;
        int maxc=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                count++;
                maxc=max(maxc,count);
            }else if(s[i]==')'){
                count--;
            }
        }   
        return maxc;
    }
};
