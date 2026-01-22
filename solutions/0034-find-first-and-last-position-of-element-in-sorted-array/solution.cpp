class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int high=n-1;
        int mid;
        int low=0;
        vector<int>ans;
        ans.push_back(-1);
        ans.push_back(-1);
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]==target){
                low=mid+1;
                ans[1]=mid;
            }else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        high=n-1;
        low=0;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]==target){
                high=mid-1;
                ans[0]=mid;
            }else if(nums[mid]>target){
                high=mid-1;    
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
