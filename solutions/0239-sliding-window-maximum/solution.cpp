class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> dq;
        vector<int> res;
        
        if (nums.size() == 1) return nums;
        
        if (k >= nums.size()) {
            int maxi = INT_MIN;
            for (auto i : nums) {
                maxi = max(maxi, i);
            }
            return {maxi}; 
        }
        
        dq.push_back({nums[0], 0});
        for (int i = 1; i < k; i++) {
            while (!dq.empty() && nums[i] >= dq.back().first) {
                dq.pop_back();
            }
            dq.push_back({nums[i], i});
        }
        
        res.push_back(dq.front().first);
        
        for (int i = k; i < nums.size(); i++) {
            if (!dq.empty() && dq.front().second == i - k) {
                dq.pop_front();
            }
            
            // FIX: Clear out smaller elements from the BACK before pushing,
            // exactly like you did in your first initialization loop.
            while (!dq.empty() && nums[i] >= dq.back().first) {
                dq.pop_back();
            }
            dq.push_back({nums[i], i});
            
            res.push_back(dq.front().first);
        }
        return res;
    }
};
