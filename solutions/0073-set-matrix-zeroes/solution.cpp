class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    unordered_set<int> targetRows;
    unordered_set<int> targetCols;

    // 1. Identify rows and columns that need to be zeroed
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                targetRows.insert(i);
                targetCols.insert(j);
            }
        }
    }

    // 2. Zero out the identified rows
    for (int i : targetRows) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }

    // 3. Zero out the identified columns
    for (int j : targetCols) {
        for (int i = 0; i < rows; i++) {
            matrix[i][j] = 0;
        }
    }
}

};
