class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        
        if(n < 4) return ans;
        
        int it1 = 0;
        while(it1 < n - 3) {
            // Skip duplicates for it1
            if(it1 != 0 && nums[it1-1] == nums[it1]) {
                it1++;
                continue;
            }
            
            int it4 = n - 1;
            while(it4 >= it1 + 3) {
                // Skip duplicates for it4
                if(it4 != n - 1 && nums[it4+1] == nums[it4]) {
                    it4--;
                    continue;
                }
                
                int it2 = it1 + 1;
                int it3 = it4 - 1;
                long long newtarget = (long long)target - nums[it4] - nums[it1];
                
                while(it3 > it2) {
                    long long currentsum = nums[it3] + nums[it2];
                    if(currentsum > newtarget) {
                        it3--;
                    } else if(currentsum < newtarget) {
                        it2++;
                    } else {
                        ans.push_back({nums[it1], nums[it2], nums[it3], nums[it4]});
                        
                        // Skip duplicates for it2 and it3
                        while(it2 < it3 && nums[it2+1] == nums[it2]) {
                            it2++;
                        }
                        while(it2 < it3 && nums[it3-1] == nums[it3]) {
                            it3--;
                        }
                        it2++;
                        it3--;
                    }
                }
                it4--;
            }
            it1++;
        }
        return ans;
    }
};
