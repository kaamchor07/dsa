class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>grid(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            grid[0][i]=1;
        }
        for(int i=0;i<m;i++){
            grid[i][0]=1;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i-1>=0 && j-1>=0){
                    grid[i][j]=grid[i-1][j]+grid[i][j-1];
                }
            }
        }
        return grid[m-1][n-1];
    }
};
