class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int currentsum=0;
        int idealsum=n;
        for(int i=0;i<n;i++){
            currentsum=currentsum+nums[i];
            idealsum=idealsum+i;
        }
        return idealsum-currentsum;
    }
};
