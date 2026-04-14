class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& req) {
        vector<vector<int>>adj(numCourses,vector<int>(0));
        vector<int>indegree(numCourses);
        int count=0;
        for(int i=0;i<req.size();i++){
            adj[req[i][1]].push_back(req[i][0]);
            indegree[req[i][0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(auto k : adj[node]){
                indegree[k]--;
                if(indegree[k]==0){
                    q.push(k);
                }
            }
        }
        if(count!=numCourses){
            return false;
        }
        return true;

    }
};
