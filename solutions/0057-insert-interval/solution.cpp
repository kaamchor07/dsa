class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        if (n == 0) return {newInterval};
        
        // 1. Find the floor index 'i' (largest start <= newInterval[0])
        int high = n - 1;
        int low = 0;
        int mid = 0;
        int i = -1;
        while (high >= low) {
            mid = low + (high - low) / 2;
            if (intervals[mid][0] == newInterval[0]) {
                i = mid;
                break;
            } else if (intervals[mid][0] < newInterval[0]) {
                i = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        // 2. Find the ceiling index 'j' (smallest end >= newInterval[1])
        high = n - 1;
        low = 0;
        int j = -1;
        while (high >= low) {
            mid = low + (high - low) / 2;
            if (intervals[mid][1] == newInterval[1]) {
                j = mid;
                break;
            } else if (intervals[mid][1] > newInterval[1]) {
                j = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        // ---- FIXED RECONSTRUCTION LOGIC ----
        
        // Step A: Push all intervals that strictly end BEFORE newInterval starts
        int k = 0;
        while (k < n && intervals[k][1] < newInterval[0]) {
            ans.push_back(intervals[k]);
            k++;
        }
        
        // Step B: Dynamically merge all overlapping intervals
        while (k < n && intervals[k][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[k][0]);
            newInterval[1] = max(newInterval[1], intervals[k][1]);
            k++;
        }
        ans.push_back(newInterval); // Push the fully merged result
        
        // Step C: Push all remaining intervals that start AFTER newInterval ends
        while (k < n) {
            ans.push_back(intervals[k]);
            k++;
        }        
        
        return ans;
    }
};
