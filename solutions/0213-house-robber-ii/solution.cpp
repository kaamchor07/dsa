class Solution {
private:
    int helper(vector<int>&nums){
        int n=nums.size();
        if(n==1)return nums[0];
        int prev=nums[0];
        int prev2=0;
        int curr=0;
        for(int i=1;i<n;i++){
            int p=nums[i];
            if(i>1)p+=prev2;
            int np=0+prev;
            curr=max(np,p);
            prev2=prev;
            prev=curr;
        }
        return curr;
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp1,temp2;
        if(n==1)return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
        }
        return max(helper(temp1),helper(temp2));
    }
};
