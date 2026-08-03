class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<string>res={"Bob","Tie","Alice"};
        vector<int>dp(n+1,INT_MIN);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int currentStonesValue=0;
            for(int k=0;k<3 && i+k<n;k++){
                currentStonesValue+=stoneValue[i+k];
                dp[i]=max(dp[i],currentStonesValue-dp[i+k+1]);
            }
        }
        if(dp[0]>0)return res[2];
        if(dp[0]<0)return res[0];
        return res[1];
    }
};
