class Solution {
public:
    int maxArea(vector<int>& height) {
        int pt1=0;
        int n=height.size();
        int pt2=n-1;
        int maxi=INT_MIN;
        while(pt1<pt2){
            int area=min(height[pt1],height[pt2])*(pt2-pt1);
            maxi=max(maxi,area);
            if(height[pt1]>height[pt2]){
                pt2--;
            }else{
                pt1++;
            }
        }
        return maxi;
    }
};
