class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate;
        int score=0;
        for(int i=0;i<nums.size();i++){
            if(score==0){
                candidate=nums[i];
                score++;
            }
            else if(nums[i]==candidate){
                score++;
            }else{
                score--;
            }
        }
        return candidate;
    }
};
