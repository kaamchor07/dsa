class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0;
        int n=numbers.size();
        int right=n-1;
        while(right>left){
            int sum=numbers[right]+numbers[left];
            if(sum>target){
                right--;
            }else if(sum==target){
                return {left+1,right+1};
            }else{
                left++;
            }
        }
        return {left+1,right+1};  
    }
};
