class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        for(const auto& i : invocations){
            adj[i[0]].push_back(i[1]);
        }
        vector<bool>sus(n,false);
        queue<int>q;
        q.push(k);
        sus[k]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto neighbour : adj[node]){
                if(!sus[neighbour]){
                    sus[neighbour]=true;
                    q.push(neighbour);
                }
            }
        }
        for(const auto& inv : invocations){
            int u=inv[0];
            int v=inv[1];
            if(!sus[u] && sus[v]){
                vector<int>ans(n);
                for(int k=0;k<n;k++){
                    ans[k]=k;
                }
                return ans;
            }
        }
        vector<int>res;
        for(int i=0;i<n;i++){
            if(!sus[i])res.push_back(i);
        }
        return res;
    }
};
