class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n;
        int pt1;
        int pt2;
        vector<int> ans;
        n=nums.size();
        if(n<=2){
            int temp;
            for(int i=0;i<n;i++){
                if(temp!=nums[i]){
                    temp=nums[i];
                    ans.push_back(temp);
                }
            }
        }else{
            sort(nums.begin(),nums.end());
            pt1=n/3;
            pt2=2*n/3;
            int n1=nums[pt1];
            int n2=nums[pt2];
            int c1=0;
            int c2=0;
            if(n1==n2){
                ans.push_back(n1);
            }else{
            for(int i=0;i<n;i++){
                if(nums[i]==n1){
                    c1++;
                }else if(nums[i]==n2){
                    c2++;
                }
            }
            if(c1>(n/3)){
                ans.push_back(n1);
            }
            if(c2>(n/3)){
                ans.push_back(n2);
            }
        }
        }
        return ans;
    }
};
