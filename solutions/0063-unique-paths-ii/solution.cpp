class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                }else{
                    grid[i][j]=1;
                }
            }
        }
        bool flag=false;
        for(int i=0;i<n;i++){
            if(flag)grid[0][i]=0;
            if(grid[0][i]==0){
                flag=true;
            }
        }
        flag=false;
        for(int i=0;i<m;i++){
            if(flag)grid[i][0]=0;
            if(grid[i][0]==0){
                flag=true;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i-1>=0 && j-1>=0 && grid[i][j]!=0){
                    grid[i][j]=grid[i-1][j]+grid[i][j-1];
                }else if(grid[i][j]==0){
                    continue;
                }
            }
        }
        return grid[m-1][n-1];
    }
};
