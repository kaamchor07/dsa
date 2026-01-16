class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int j=(-1);
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                j=i;
                break;
            }
        }
        if(j==(-1)){
            reverse(nums.begin(),nums.end());
        }else{
            int k=INT_MAX;
            int ki=nums.size()-1;
            while (nums[ki] <= nums[j-1]) {
                ki--;
            }
            swap(nums[j-1],nums[ki]);
            reverse(nums.begin()+j,nums.end());
        }
    
    }
};
