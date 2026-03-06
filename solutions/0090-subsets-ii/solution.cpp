class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>current;
        sort(nums.begin(),nums.end());
        helper(nums,ans,current,0);
        return ans;
    }
    void helper(vector<int>&nums,vector<vector<int>>&ans,vector<int>&current,int index){
            if(index==nums.size()){
            ans.push_back(current);
            return;
        }
        current.push_back(nums[index]);
        helper(nums,ans,current,index+1);
        current.pop_back();
        while(index<nums.size()-1 && nums[index]==nums[index+1]){
            index++;
        }
        helper(nums,ans,current,index+1);
    }
};
