class Solution {
private:
    int dfs(int node,vector<vector<int>>&graph,vector<int>&state){
        int res=0;
        for(auto i : graph[node]){
            if(state[i]==1 || state[i]==3){
            return 3;
            }
            if(state[i]==2){
                state[i]=2;
                res=2;
            }
            if(state[i]==0){
                state[i]=1;
                res=dfs(i,graph,state);
            }
            if(res!=2) return 3;
        }
        state[node]=2;
        return 2;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>ans;
        vector<int>state(n,0);
        for(int i=0;i<n;i++){
            if(state[i]==0){
                state[i]=1;
                int res=dfs(i,graph,state);
                state[i]=res;
            }
            if(state[i]==2){
                ans.push_back(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
