class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>visited;
        vector<int>temp(n);
        for(int i=0;i<m;i++){
            visited.push_back(temp);
        }
        int rotten=0;
        int total=0;
        queue<pair<pair<int,int>,int>> que;
        // r,c,t
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    que.push({{i,j},0});
                    visited[i][j]=2;
                    rotten++;
                }
                if(grid[i][j]!=0){
                    total++;
                }
            }
        }
        int time=0;
        int drow[]={1,0,-1,0};
        int dcolumn[]={0,1,0,-1};
        while(!que.empty()){
            int r=que.front().first.first;
            int c=que.front().first.second;
            int t=que.front().second;
            time=t;
            que.pop();
            for(int i=0;i<4;i++){
                int row=r+drow[i];
                int column=c+dcolumn[i];
                if(row>=0 && column>=0 && column<n && row<m && visited[row][column]==0 && grid[row][column]==1){
                    rotten++;
                    que.push({{row,column},t+1});
                    visited[row][column]=2;
                }
            }
        }
        if(rotten==total){
            return time;
        }
        return -1;
    }
};
