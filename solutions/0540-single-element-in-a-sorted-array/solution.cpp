class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int high=n-1;
        int low=0;
        int mid;
        if(n==1){
            return nums[0];
        }
        while(high>=low){
            mid=low+(high-low)/2;
            if(low==high){
                break;
            }
            if(nums[mid]==nums[mid+1]){
                if((high-mid)%2==1){
                    high=mid-1;
                }else{
                    low=mid+2;
                }
            }else if(nums[mid]==nums[mid-1]){
                if((high-mid)%2==0){
                    high=mid-2;
                }else{
                    low=mid+1;
                }
            }else{
                break;
            }
        }
        return nums[mid];
    }
};
