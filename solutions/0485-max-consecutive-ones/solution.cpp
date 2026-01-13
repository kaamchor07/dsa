class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int current=0;
        int maximum=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                current++;
                maximum=max(current,maximum);
            }else{
                current=0;
            }
        }
        return maximum;
    }
};
