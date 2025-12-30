class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1;
        int len=nums.size();
        if(len==0) return 0;
        for(int j=1;j<len;j++){
            if(nums[j]!=nums[i-1]){
                nums[i]=nums[j];
                i++;
            }
        }
        return i;
    }
};
