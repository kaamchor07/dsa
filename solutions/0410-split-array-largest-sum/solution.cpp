class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int mid;
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(high>=low){
            mid=low+(high-low)/2;
            int parts=1;
            int sum=0;
            for(int i=0;i<n;i++){
                if(sum+nums[i]<=mid){
                    sum+=nums[i];
                }else{
                    parts++;
                    sum=nums[i];
                }
            }
            if(parts>k){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low;
    }
};
