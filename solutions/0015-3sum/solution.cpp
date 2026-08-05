class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>res;
        for(int i=0;i<n-2;i++){
            int left=i+1;
            int right=n-1;
            int sum=nums[i];
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            while(right>left){
                sum=nums[i]+nums[left]+nums[right];
                if(sum>0){
                    right--;
                    
                }else if(sum==0){
                    res.push_back({nums[i],nums[left],nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                }else{
                    left++;
                    
                }
            }
        }
        return res;
    }
};
