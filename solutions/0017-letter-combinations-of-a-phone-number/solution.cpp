class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return {};
        vector<string>res;
        string curstring="";
        vector<string>pad = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        backtrack(0,curstring,digits,pad,res);
        return res;
    }
    void backtrack(int index,string& curstring,const string&digits,const vector<string>&pad,vector<string>&res){
        if(index==digits.length()){
            res.push_back(curstring);
            return;
        }
        int digit=digits[index]-'0';
        string letters=pad[digit];
        for(char letter : letters){
            curstring.push_back(letter);
            backtrack(index+1,curstring,digits,pad,res);
            curstring.pop_back();
        }
    }
};
