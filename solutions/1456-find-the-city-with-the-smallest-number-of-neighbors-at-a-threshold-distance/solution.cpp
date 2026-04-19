class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>matrix(n,vector<int>(n,1e5));
        for(auto i : edges){
            matrix[i[0]][i[1]]=i[2];
            matrix[i[1]][i[0]]=i[2];
        }
        for(int i=0;i<n;i++){
            matrix[i][i]=0;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(matrix[i][k]!=1e5 && matrix[k][j]!=1e5){
                        matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                    }
                }
            }
        }
        int city=-1;
        int mini=1e5;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(i!=j && matrix[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count<=mini){
                city=i;
                mini=count;
            }
        }
        return city;
    }
};
