class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> que;
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>> visited(m,vector<int>(n,-1));
        que.push({sr,sc});
        int drow[]={0,1,-1,0};
        int dcol[]={1,0,0,-1};
        int og=image[sr][sc];
        image[sr][sc]=color;
        while(!que.empty()){
            int r=que.front().first;
            int c=que.front().second;
            que.pop();
            for(int i=0;i<4;i++){
                int row=r+drow[i];
                int col=c+dcol[i];
                if(row>=0 && col>=0 && col<n && row<m && visited[row][col]==-1 && image[row][col]==og){
                    que.push({row,col});
                    visited[row][col]=1;
                    image[row][col]=color;
                }
            }
        }
        return image;
    }
};
