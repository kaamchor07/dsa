class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n-2;i++){
            if(i!=0 && nums[i]==nums[i-1]){
                continue;
            }else{
                int j=i+1;
                int k=n-1;
                while(j<k){
                    int sum=nums[j]+nums[k]+nums[i];
                    if(sum>0){
                        k--;
                    }else if(sum<0){
                        j++;
                    }else{
                        vector<int>temp={nums[i],nums[j],nums[k]};
                        ans.push_back(temp);
                        while(j<n-1 && nums[j]==nums[j+1]){
                            j++;
                        }
                        
                        while(0<k && nums[k]==nums[k-1]){
                            k--;
                        }
                        k--;
                        j++;
                    }
                }
            }

        }
        return ans;
    }
};
