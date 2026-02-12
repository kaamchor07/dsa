class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        
        // 1. OPTIMIZATION: Find the Right Boundary (max_col)
        // Binary search on Row 0 to find the last column <= target
        int low = 0, high = n - 1;
        int max_col = n - 1; 
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            if (matrix[0][mid] == target) return true;
            
            if (matrix[0][mid] < target) {
                low = mid + 1; // Look right
            } else {
                max_col = mid - 1; // Mid is too big, limit moves left
                high = mid - 1;
            }
        }
        // If target is smaller than the smallest element in row 0
        if (max_col < 0) return false; 

        // 2. OPTIMIZATION: Find the Bottom Boundary (max_row)
        // Binary search on Column 0 to find the last row <= target
        low = 0; high = m - 1;
        int max_row = m - 1;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            if (matrix[mid][0] == target) return true;
            
            if (matrix[mid][0] < target) {
                low = mid + 1; // Look down
            } else {
                max_row = mid - 1; // Mid is too big, limit moves up
                high = mid - 1;
            }
        }
        
        // 3. STAIRCASE TRAVERSAL
        // Start from Bottom-Left of our "Optimized Box"
        // Row starts at max_row, Col starts at 0
        int row = max_row;
        int col = 0;
        
        while (row >= 0 && col <= max_col) {
            int val = matrix[row][col];
            
            if (val == target) {
                return true;
            } else if (val > target) {
                row--; // Too big? Move Up
            } else {
                col++; // Too small? Move Right
            }
        }
        
        return false;
    }
};
