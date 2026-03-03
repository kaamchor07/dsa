class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int open=n-1;
        int close=n;
        vector<string>ans;
        helper("(",close,open,ans);
        return ans;
    }
    void helper(string str,int close,int open,vector<string>&ans){
        if(close==0 && open==0){
            ans.push_back(str);
            return;
        }
        if(close==open){
            helper(str+'(',close,open-1,ans);
        }
        if(close>open){
            helper(str+')',close-1,open,ans);
            if(open!=0){
                helper(str+'(',close,open-1,ans);
            }
        }
    }
};
