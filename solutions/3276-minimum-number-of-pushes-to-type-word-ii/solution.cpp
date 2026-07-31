class Solution {
public:
    int minimumPushes(string word) {
        vector<int>counts(26,0);
        for(auto i : word){
            counts[i-'a']++;
        }
        int ans=0;
        sort(counts.begin(),counts.end(),greater<int>());
        int distinct=0;
        for(int i=0;i<26;i++){
            if(counts[i]!=0){
                distinct++;
                if(distinct<=8){
                    ans+=counts[i];
                }else if(distinct<=16){
                    ans+=counts[i]*2;
                }else if(distinct<=24){
                    ans+=counts[i]*3;
                }else{
                    ans+=counts[i]*4;
                }
            }
        }
        return ans;
    }
};
