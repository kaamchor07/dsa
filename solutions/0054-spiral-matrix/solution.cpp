class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int ysteps = matrix.size();
        int xsteps = matrix[0].size();
        vector<int> ans;
        
        int i = 0;
        int j = -1; // Start at -1 so the first move lands at [0][0]

        while (xsteps > 0 && ysteps > 0) {
            // 1. Move Right
            for (int x = 0; x < xsteps; x++) {
                j++;
                ans.push_back(matrix[i][j]);
            }
            ysteps--; // We finished a full horizontal row
            if (ysteps == 0) break;

            // 2. Move Down
            for (int y = 0; y < ysteps; y++) {
                i++;
                ans.push_back(matrix[i][j]);
            }
            xsteps--; // We finished a full vertical column
            if (xsteps == 0) break;

            // 3. Move Left
            for (int x = 0; x < xsteps; x++) {
                j--;
                ans.push_back(matrix[i][j]);
            }
            ysteps--; // Finished another row
            if (ysteps == 0) break;

            // 4. Move Up
            for (int y = 0; y < ysteps; y++) {
                i--;
                ans.push_back(matrix[i][j]);
            }
            xsteps--; // Finished another column
        }
        return ans;
    }
};
