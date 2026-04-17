class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        set<pair<int,pair<int,int>>>s;
        int rows=heights.size();
        int cols=heights[0].size();
        vector<vector<int>>visited(rows,vector<int>(cols,1e9));
        s.insert({0,{0,0}});
        visited[0][0]=0;
        int drow[]={0,1,0,-1};
        int dcol[]={1,0,-1,0};
        while(!s.empty()){
            auto it = *(s.begin());
            int row=it.second.first;
            int col=it.second.second;
            int eff=it.first;
            if(row==rows-1 && col==cols-1)return eff;
            s.erase(it);
            for(int i=0;i<4;i++){
                int r=row+drow[i];
                int c=col+dcol[i];
                if(r>=0 && c>=0 && r<rows && c<cols && visited[r][c]>max(eff,abs(heights[r][c]-heights[row][col]))){
                    s.erase({visited[r][c],{r,c}});
                    s.insert({max(eff,abs(heights[r][c]-heights[row][col])),{r,c}});
                    visited[r][c]=max(eff,abs(heights[r][c]-heights[row][col]));
                }
            }
        }
        return visited[rows-1][cols-1];
    }
};
