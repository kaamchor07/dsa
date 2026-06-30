class Solution {
public:
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
};
