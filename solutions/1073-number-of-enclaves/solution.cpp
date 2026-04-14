class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int count=0;
        int rows=grid.size();
        int cols=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>visited(rows,vector<int>(cols,0));
        for(int i=0;i<cols;i++){
            if(grid[0][i]==1){
                q.push({0,i});
                visited[0][i]=1;
            }
            if(grid[rows-1][i]==1){
                q.push({rows-1,i});
                visited[rows-1][i]=1;
            }
        }
        for(int i=1;i<rows-1;i++){
            if(grid[i][0]==1){
                q.push({i,0});
                visited[i][0]=1;
            }
            if(grid[i][cols-1]==1){
                q.push({i,cols-1});
                visited[i][cols-1]=1;
            }
        }
        int drow[]={0,1,0,-1};
        int dcol[]={1,0,-1,0};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int r=row+drow[i];
                int c=col+dcol[i];
                if(r>=0 && c>=0 && r<rows && c<cols && visited[r][c]==0 && grid[r][c]==1){
                    q.push({r,c});
                    visited[r][c]=1;
                }
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1 && visited[i][j]==0){
                    count++;
                }
            }
        }
        return count;
    }
};
