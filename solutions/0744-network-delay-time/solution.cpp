class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        set<int>s;
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<times.size();i++){
            adj[times[i][0]-1].push_back({times[i][1]-1,times[i][2]});
        }
        vector<int>cost(n,1e9);
        s.insert(k-1);
        cost[k-1]=0;
        while(!s.empty()){
            auto it=*(s.begin());
            int node=it;
            s.erase(node);
            for(auto i : adj[node]){
                int n=i.first;
                int d=i.second;
                if(cost[n]>cost[node]+d){
                    cost[n]=cost[node]+d;
                    s.insert(n);
                }
            }
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            if(cost[i]==1e9)return -1;
            ans=max(ans,cost[i]);
        }
        return ans;
    }
};
