class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string temp=strs[0];
        for(int i=1;i<n;i++){
            int s=0;
            while(s<temp.size()){
                if(temp.substr(0,s+1)==strs[i].substr(0,s+1)){
                    s++;
                }else{
                    temp=temp.substr(0,s);
                    break;
                }
            }
            if(temp==""){
                return temp;
            }
        }
        return temp;
    }
};
