class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans={{1},{1,1}};
        vector<int> tempprev={1,1};
        int n =numRows;
        if(n==1){
            ans.pop_back();
            return ans;
        }else if(n==2){
            return ans;
        }else{
            for(int i=3;i<=n;i++){
                vector<int>temp(i,1);
                for(int j=1;j<(i+1)/2;j++){
                    temp[j]=tempprev[j]+tempprev[j-1];
                    temp[i-j-1]=temp[j];
                }
                ans.push_back(temp);
                tempprev=temp;
            }
            return ans;
        }

    }
};
