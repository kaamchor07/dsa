class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        if(m==1)return triangle[0][0];
        for(int i=1;i<m;i++){
            int n=triangle[i].size();
            for(int j=0;j<n;j++){
                if(j==0){triangle[i][j]+=triangle[i-1][j];}
                else if(j==n-1){triangle[i][j]+=triangle[i-1][j-1];}
                else{
                    triangle[i][j]+=min(triangle[i-1][j],triangle[i-1][j-1]);
                }
                
            }
        }
        int mini=INT_MAX;
        for(const auto& i : triangle[m-1]){
            mini=min(mini,i);
        }
        return mini;
    }
};
