class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>earnings(n,INT_MIN);
        if(n==1)return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        earnings[0]=nums[0];
        earnings[1]=nums[1];
        if(n>=3)earnings[2]=max(nums[0]+nums[2],nums[1]);
        for(int i=3;i<n;i++){
            earnings[i]=nums[i]+max(earnings[i-2],earnings[i-3]);
        }
        return max(earnings[n-1],earnings[n-2]);
    }
};
