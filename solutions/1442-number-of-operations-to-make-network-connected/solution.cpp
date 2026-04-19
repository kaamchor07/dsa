class DSU{
    public:
        vector<int>s,parent;
        DSU(int n){
            s.resize(n,1);
            parent.resize(n);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        int findUParent(int u){
            if(parent[u]==u)return u;
            return parent[u]=findUParent(parent[u]);
        }
        void unionBySize(int u,int v){
            int ulp_u=findUParent(u);
            int ulp_v=findUParent(v);
            if(ulp_u==ulp_v) return;
            if(s[ulp_u]>s[ulp_v]){
                parent[ulp_v]=ulp_u;
                s[ulp_u]+=s[ulp_v];
            }else{
                parent[ulp_u]=ulp_v;
                s[ulp_v]+=s[ulp_u];
            }
        }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU ds(n);
        int extra=0;
        int comp=0;
        for(const auto& i : connections){
            if(ds.findUParent(i[0])==ds.findUParent(i[1])){
                extra++;
            }else{
                ds.unionBySize(i[0],i[1]);
            }
        }
        for(int i=0;i<n;i++){
            if(ds.findUParent(i)==i){
                comp++;
            }
        }
        if(extra>=comp-1) return comp-1;
        return -1;
    }
};
