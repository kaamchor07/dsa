class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        vector<vector<int>> ans;
        // bool flag=false;
        // sort(intervals.begin(),intervals.end());
        // for(int i=0;i<(intervals.size()-1);i++){
        //     if(intervals[i][1]>=intervals[i+1][0] && flag==false && intervals[i][1]<=intervals[i+1][1]){
        //         ans.push_back({intervals[i][0],intervals[i+1][1]});
        //         flag=true;
        //     }else if(intervals[i][1]>=intervals[i+1][0] && flag==true && intervals[i][1]<=intervals[i+1][1]){
        //         auto temp={ans[ans.size()-1][0],intervals[i+1][1]};
        //         ans.pop_back();
        //         ans.push_back(temp);
        //         flag=true;
        //     }else{
        //         if(flag==false){
        //             ans.push_back({intervals[i][0],intervals[i][1]});
        //         }
        //         flag=false;
        //     }

        // }
        // if(flag==false){
        //     ans.push_back({intervals[intervals.size()-1][0],intervals[intervals.size()-1][1]});
        // }


        if(intervals.empty()){
            return ans;
        }
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(ans.back()[1]>=intervals[i][0]){
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
