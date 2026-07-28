class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int res=0;
        int prev_end=intervals[0][1];
        for(int i=1;i<n;i++){
            if(prev_end>intervals[i][0]){
                res++;
                prev_end = min(prev_end, intervals[i][1]);
            }else{
                prev_end=intervals[i][1];
            }
        }
        return res;
    }
};
