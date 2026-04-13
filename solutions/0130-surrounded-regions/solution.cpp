class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>>q;
        int rows=board.size();
        int cols=board[0].size();
        vector<vector<int>>visited(rows,vector<int>(cols,0));
        for(int i=0;i<rows;i++){
            if(board[i][cols-1]=='O'){
                q.push({i,cols-1});
                visited[i][cols-1]=1;
            }
            if(board[i][0]=='O'){
                q.push({i,0});
                visited[i][0]=1;
            }
        }
        for(int i=1;i<cols-1;i++){
            if(board[0][i]=='O'){
                q.push({0,i});
                visited[0][i]=1;
            }
            if(board[rows-1][i]=='O'){
                q.push({rows-1,i});
                visited[rows-1][i]=1;
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
                if(r>=0 && c>=0 && r<rows && c<cols && visited[r][c]==0 && board[r][c]=='O'){
                    q.push({r,c});
                    visited[r][c]=1;
                } 
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(visited[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
                    
    }
};
