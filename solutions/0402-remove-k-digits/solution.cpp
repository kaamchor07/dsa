class Solution {
public:
    string removeKdigits(string num, int k) {
        string res="";
        for(char c : num){
            while(!res.empty() && res.back()>c && k>0){
                res.pop_back();
                k--;
            }
            res.push_back(c);
        }
        while(k>0 && !res.empty()){
            res.pop_back();
            k--;
        }
        int start=0;
        while(start<res.size() && res[start]=='0'){
            start++;
        }
        res=res.substr(start);
        return res.empty() ? "0" : res;
    }
};
