class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>count(26,0);
        for(char c : s){
            count[c-'a']++;
        }
        int n=s.size();
        if(n==1)return s;
        string ans(n,' ');
        if(n%2==1){
            for(int i=0;i<26;i++){
                if(count[i]%2==1){
                    ans[n/2]='a'+i;
                    count[i]--;
                    break;
                }
            }
        }
        int index=0;
        for(int i=0;i<26;i++){
            int temp=count[i]/2;
            for(int j=0;j<temp;j++){
                ans[index]=i+'a';
                ans[n-index-1]=i+'a';
                index++;
            }
        }
        return ans;
    }
};
