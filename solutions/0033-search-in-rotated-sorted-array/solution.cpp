class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int high=n-1;
        int low=0;
        int mid;
        int temp;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[high]>nums[mid]){
                high=mid;
            }else{
                low=mid+1;
            }
        }

        low=mid;
        high=low+n-1;
        while(high>=low){
            mid=(low+(high-low)/2);
            if(nums[mid%n]>target){
                high=mid-1;
            }else if(nums[mid%n]<target){
                low=mid+1;
            }else{
                return mid%n;
            }
        }
        return -1;
    }
};
