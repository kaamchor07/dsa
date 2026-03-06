class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>current;
        helper(candidates,target,0,current,ans,0);
        return ans;
    }

    void helper(vector<int>& candidates,int target,int sum,vector<int>&current,vector<vector<int>>&ans,int index){
        if(sum==target){
            ans.push_back(current);
            return;
        }
        if(sum>target || index==candidates.size())return;
        current.push_back(candidates[index]);
        helper(candidates,target,sum+candidates[index],current,ans,index);
        current.pop_back();
        helper(candidates,target,sum,current,ans,index+1);
    }
};
