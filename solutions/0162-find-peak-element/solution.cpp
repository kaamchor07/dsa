class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int high=n-1;
        int low=0;
        int mid;
        if(n==1){
            return 0;
        }
        while(high>=low){
            mid=low+(high-low)/2;
            if(mid==0 && nums[mid]>nums[mid+1]){
                return 0;
            }else if(mid==n-1 && nums[mid]>nums[mid-1]){
                return n-1;
            }
            if(nums[mid+1]>nums[mid]){
                low=mid+1;
            }else if(nums[mid-1]>nums[mid]){
                high=mid-1;
            }else{
                return mid;
            }
        }
        return mid;
    }
};
