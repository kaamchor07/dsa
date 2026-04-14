class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        stack<int>s;
        int n=adj.size();
        vector<int>visited(n,0); //visited then team 1 or -1 and 0 if unvisited
        int nextteam=1;
        for(int k=0;k<n;k++){
            if(visited[k]==0){
                s.push(k);
                visited[k]=nextteam;
                while(!s.empty()){
                    int node=s.top();
                    s.pop();
                    int myteam=visited[node];
                    for(auto i : adj[node]){
                        if(visited[i]==0){
                            s.push(i);
                            nextteam=-1*myteam ;
                            visited[i]=nextteam;
                        }else if(visited[i]==myteam){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
