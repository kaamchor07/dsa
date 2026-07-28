class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>>pq;
        for(int i=0;i<points.size();i++){
            int dist=pow(points[i][0],2)+pow(points[i][1],2);
            if(pq.size()<k){
                pq.push({dist,i});
            }else{
                if(pq.top().first>dist){
                    pq.pop();
                    pq.push({dist,i});
                }
            }
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            int index=pq.top().second;
            pq.pop();
            ans.push_back(points[index]);
        }
        return ans;
    }
};
