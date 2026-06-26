class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>s;
        int n=nums.size();
        vector<int>ans(n,-1);
        for(int i=2*nums.size()-1;i>=0;--i){
            int num=nums[i%n];
            while(!s.empty() && s.top()<=num){
                s.pop();
            }
            if(i<n)ans[i]=s.empty() ? -1 : s.top();
            s.push(num);
            
        }
        return ans;
    }
};
