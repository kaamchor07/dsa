class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows=mat.size();
        int cols=mat[0].size();
        vector<vector<int>>dist(rows,vector<int>(cols,-1));
        queue<pair<int,int>>q;
        int drow[]={1,0,-1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int r=row+drow[i];
                int c=col+dcol[i];
                if(r>=0 && c>=0 && r<rows && c<cols && dist[r][c]==-1){
                    q.push({r,c});
                    dist[r][c]=dist[row][col]+1;
                }
            }
        }
        return dist;
    }
};
