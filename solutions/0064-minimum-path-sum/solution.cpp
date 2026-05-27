class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)continue;
                int c1=INT_MAX;
                int c2=INT_MAX;
                if(i-1>=0)c1=grid[i-1][j]+grid[i][j];
                if(j-1>=0)c2=grid[i][j-1]+grid[i][j];
                grid[i][j]=min(c1,c2);
            }
        }
        return grid[m-1][n-1];   
    }
};
