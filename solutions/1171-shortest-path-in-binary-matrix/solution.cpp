class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int xstep[]={0,0,1,1,1,-1,-1,-1};
        int ystep[]={1,-1,1,-1,0,0,1,-1};
        int rows=grid.size();
        int cols=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        if(grid[0][0]==0){
            q.push({{0,0},1});
        }
        vector<vector<int>>visited(rows,vector<int>(cols,0));
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int dist=q.front().second;
            if(x==rows-1 && y==cols-1) return dist;
            q.pop();
            for(int i=0;i<8;i++){
                int xn=x+xstep[i];
                int yn=y+ystep[i];
                if(xn>=0 && yn>=0 && xn<rows && yn<cols && visited[xn][yn]==0 && grid[xn][yn]==0){
                    visited[xn][yn]=1;
                    q.push({{xn,yn},dist+1});
                } 
            }

        }
        return -1;
    }
};
