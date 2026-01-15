class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int side=matrix.size();
        if(side<=1){
            return;
        }
        int i=0;
        int j=0;
        while(side>1){
            if(side<=1){
                return;
            }
            for(int offset=0;offset<side-1;offset++){
                swap(matrix[i][j+offset],matrix[i+side-offset-1][j]);
                swap(matrix[i+side-offset-1][j],matrix[i+side-1][j+side-offset-1]);
                swap(matrix[i+side-1][j+side-offset-1],matrix[i+offset][j+side-1]);
            }
            side=side-2;
            i++;
            j++;
        }
    }
};
