class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int high=nums[0];
        for(int i=0;i<n;i++){
            if(nums[i]>high){
                high=nums[i];
            }
        }
        int low=1;
        int mid;
        while(high>=low){
            mid=low+(high-low)/2;
            int count=0;
            for(int i=0;i<n;i++){
                count=count+((nums[i]-1)/mid +1);
            }
            if(count<=threshold){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};
