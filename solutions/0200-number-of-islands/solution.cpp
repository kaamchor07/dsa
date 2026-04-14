class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int,int>>q;
        int rows=grid.size();
        int cols=grid[0].size();
        int count=0;
        vector<vector<int>>visited(rows,vector<int>(cols,0));
        int drow[]={1,0,-1,0};
        int dcol[]={0,-1,0,1};
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(visited[i][j]==0 && grid[i][j]=='1'){
                    visited[i][j]=1;
                    q.push({i,j});
                    count++;
                    while(!q.empty()){
                        int row=q.front().first;
                        int col=q.front().second;
                        q.pop();
                        for(int k=0;k<4;k++){
                            int r=row+drow[k];
                            int c=col+dcol[k];
                            if(r>=0 && c>=0 && r<rows && c<cols && visited[r][c]==0 && grid[r][c]=='1'){
                                visited[r][c]=1;
                                q.push({r,c});
                            }
                        }

                    }
                }
            }
        }
        return count;
    }
};
