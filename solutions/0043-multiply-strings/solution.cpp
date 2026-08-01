class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int n1=num1.length();
        int n2=num2.length();
        vector<int>result(n1+n2,0);
        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                int mul=(num1[i]-'0')*(num2[j]-'0');
                int sum=mul+result[i+j+1];
                result[i+j+1]=sum%10;
                result[i+j]+=sum/10;
            }
        }
        string ans="";
        int idx=0;
        while(idx<result.size()&& result[idx]==0){
            idx++;
        }
        while(idx<result.size()){
            ans+=to_string(result[idx]);
            idx++;
        }
        return ans;
    }
};
