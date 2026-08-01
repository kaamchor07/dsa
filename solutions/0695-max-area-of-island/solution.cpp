class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        int drow[] = {0, 0, 1, -1};
        int dcol[] = {1, -1, 0, 0};
        int maxi = 0;
        
        queue<pair<int, int>> q;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Only start BFS from unvisited land cells
                if (grid[i][j] == 1 && !visited[i][j]) {
                    visited[i][j] = true; // Mark visited IMMEDIATELY when pushed
                    q.push({i, j});
                    int count = 0;
                    
                    while (!q.empty()) {
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();
                        count++;
                        
                        for (int k = 0; k < 4; k++) {
                            int r = row + drow[k];
                            int c = col + dcol[k];
                            
                            // Check bounds, land value, and visited status
                            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1 && !visited[r][c]) {
                                visited[r][c] = true; // Mark visited IMMEDIATELY when pushed
                                q.push({r, c});
                            }
                        }
                    }
                    maxi = max(maxi, count);
                }
            }
        }
        
        return maxi;
    }
};
