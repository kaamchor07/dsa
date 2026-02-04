class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        int n=s.size();
        for(int i=0;i<n;i++){
            bool flag=true;
            for(int j=0;j<n && flag;j++){
                if(s[(i+j)%n]!=goal[j]){
                    flag=false;
                }
            }
            if(flag==true)return true;
        }
        return false;
    }
};
