class Solution {
private:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        vector<int>ps(n);
        vector<int>ns(n);
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>heights[i]){
                s.pop();
            }
            ps[i]=s.empty() ? -1 : s.top();
            s.push(i);
        }
        while(!s.empty())s.pop();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            ns[i]= s.empty() ? n : s.top();
            s.push(i);
        }
        int maxarea=INT_MIN;
        for(int i=0;i<n;i++){
            int area=(ns[i]-ps[i]-1)*(heights[i]);
            maxarea=max(area,maxarea);
        }
        return maxarea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>heights(n);
        int maxarea=INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    heights[j]++;
                }else{
                    heights[j]=0;
                }
            }
            int area=largestRectangleArea(heights);
            maxarea=max(area,maxarea);
        }
        return maxarea;
    }
};
