class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        // if(s.size()==1)return false;
        unordered_map<char,char>m;
        m[']']='[';
        m[')']='(';
        m['}']='{';
        for(int i=0;i<s.size();i++){
            if(s[i]=='{' || s[i]=='(' || s[i]=='['){
                st.push(s[i]);
            }else{
                if(!st.empty()){
                    auto temp=st.top();
                    if(m[s[i]]==temp){
                        st.pop();
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }

            }
        }
        if(st.empty())return true;
        return false;
    }
};
