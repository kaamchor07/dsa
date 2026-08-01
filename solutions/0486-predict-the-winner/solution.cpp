class Solution {
public:
    int memo[20][20];
    int maxDiff(vector<int>&nums,int i,int j){
        if(i==j)return nums[i];
        if(memo[i][j]!=-1)return memo[i][j];
        int takeleft=nums[i]-maxDiff(nums,i+1,j);
        int takeright=nums[j]-maxDiff(nums,i,j-1);
        return memo[i][j]=max(takeright,takeleft);
    }
    bool predictTheWinner(vector<int>& nums) {
        if(nums.size()%2==0)return true;
        memset(memo, -1, sizeof(memo));
        return maxDiff(nums,0,nums.size()-1)>=0;

    }
};
