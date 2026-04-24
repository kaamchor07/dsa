class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int temp=0;
        int maxi=0;
        int n=nums.size();
        for(int right=0;right<n;right++){
            if(temp==k && nums[right]==0){
                if(nums[left]==0){
                    left++;
                }else{
                    while(nums[left]==1){
                        left++;
                    }
                    left++;
                }
            }else{
                if(nums[right]==0){
                    temp++;
                }
                maxi=max(maxi,right-left+1);
            }
        }
        return maxi;
    }
};
