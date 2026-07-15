class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int currmax=0;
        for(int i=0;i<nums.size();i++){
            currmax=max(nums[i],currmax+nums[i]);
            maxi=max(currmax,maxi);
        }
        return maxi;
    }
};
