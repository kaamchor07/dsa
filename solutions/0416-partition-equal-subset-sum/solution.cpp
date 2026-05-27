class Solution {
private:
    bool helper(int index,int currsum,vector<int>& nums,int& sum,vector<vector<int>>&memo){
        if(currsum==sum)return true;
        if(index==nums.size())return false;
        if(memo[index][currsum]!=-1)return memo[index][currsum];
        bool f=false;
        if(nums[index]+currsum<=sum){
            f=helper(index+1,currsum+nums[index],nums,sum,memo);}
        if(f==true)return memo[index][currsum]=1;;
        return memo[index][currsum]=helper(index+1,currsum,nums,sum,memo);

    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        
        for(const auto& i : nums){
            sum+=i;
        }
        if(sum%2==1)return false;
        sum=sum/2;
        vector<vector<int>>memo(nums.size(),vector<int>(sum+1,-1));
        return helper(0,0,nums,sum,memo);
    }
};
