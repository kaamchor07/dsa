class Solution {
public:
    int m,n;
    int drow[4]={0,0,-1,1};
    int dcol[4]={1,-1,0,0};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m=heights.size();
        n=heights[0].size();
        vector<vector<bool>>pacific(m,vector<bool>(n,false));
        vector<vector<bool>>atlantic(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            dfs(i,0,heights,pacific);
        }
        for(int j=0;j<n;j++){
            dfs(0,j,heights,pacific);
        }
        for(int i=0;i<m;i++){
            dfs(i,n-1,heights,atlantic);
        }
        for(int j=0;j<n;j++){
            dfs(m-1,j,heights,atlantic);
        }
        vector<vector<int>>ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(atlantic[i][j] && pacific[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
    void dfs(int i,int j,vector<vector<int>>&heights,vector<vector<bool>>&visited){
        visited[i][j]=true;
        stack<pair<int,int>>s;
        s.push({i,j});
        while(!s.empty()){
            int row=s.top().first;
            int col=s.top().second;
            s.pop();
            for(int k=0;k<4;k++){
                int r=row+drow[k];
                int c=col+dcol[k];
                if(r>=0 && c>=0 && r<m && c<n && heights[row][col]<=heights[r][c] && visited[r][c]==false){
                    s.push({r,c});
                    visited[r][c]=true;
                }
            }
        }
    }
};
