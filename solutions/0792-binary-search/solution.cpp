class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int high=n-1;
        int mid;
        int low=0;
        while(high>=low){
            mid=low+(high-low)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return -1;
    }    
};
