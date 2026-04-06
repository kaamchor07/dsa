class Solution {
private:
    void dfs(vector<vector<int>>& isConnected,int node,int n,vector<int>&visited){
        visited[node]=1;
        for(int neighbour=0;neighbour<n;neighbour++){
            if(visited[neighbour]==0 & isConnected[node][neighbour]==1){
                dfs(isConnected,neighbour,n,visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>visited(n);
        int count=0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                dfs(isConnected,i,n,visited);
                count++;
            }
        }
        return count;
    }
};
