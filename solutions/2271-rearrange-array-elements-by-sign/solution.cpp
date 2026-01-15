class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;
        if(nums.size()==0){
            return nums;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                pos.push_back(nums[i]);
            }else{
                neg.push_back(nums[i]);
            }
        }
        int index=0;
        int i=0;
        int j=0;
        while(index<nums.size()){
            nums[index]=pos[i];
            i++;
            index++;
            nums[index]=neg[j];
            j++;
            index++;
        }
        
        return nums;
    }
};
