class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int high=n-1;
        int low=0;
        int mid;
        while(high>=low){
            mid=low+(high-low)/2;
            if(nums[mid]<nums[high]){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return nums[mid];
    }
};
