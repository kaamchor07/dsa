class Solution {
private:
    map<pair<int,int>,int>memo;
    int helper(int index,int sum,int& target,vector<int>& nums){
        if(sum==target && index==nums.size())return 1;
        if(index==nums.size()) return 0;
        pair<int,int> state={index,sum};
        if(memo.find(state)!=memo.end()){
            return memo[state];
        }
        return memo[state]=helper(index+1,sum+nums[index],target,nums)+helper(index+1,sum-nums[index],target,nums);
    }    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        memo.clear();
        return helper(0,0,target,nums);
    }
};
