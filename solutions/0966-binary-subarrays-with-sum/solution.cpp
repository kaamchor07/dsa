class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i = 0;
        int cur = 0;
        int count = 0;
        int prefix_zeros = 0;
        
        for (int j = 0; j < nums.size(); j++) {
            cur += nums[j];
            
            // If we overshoot the goal, shrink window and reset prefix zero tracking
            while (i < j && (cur > goal || nums[i] == 0)) {
                if (nums[i] == 1) {
                    prefix_zeros = 0; // Reset because we broke the zero chain
                } else {
                    prefix_zeros++;
                }
                cur -= nums[i];
                i++;
            }
            
            // If the current window exactly matches the goal
            if (cur == goal) {
                // An empty window (i > j) isn't valid, but if goal == 0, a single 0 is valid
                if (i <= j || goal == 0) {
                    count += 1 + prefix_zeros;
                }
            }
        }
        
        return count;
    }
};
