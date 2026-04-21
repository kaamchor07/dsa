class DSU{
    public:
        vector<int>s,parent;
        DSU(int n){
            s.resize(n,1);
            parent.resize(n);
            for(int i =0;i<n;i++){
                parent[i]=i;
            }
        }
        int findUParent(int u){
            if(parent[u]==u)return u;
            return parent[u]=findUParent(parent[u]);
        }
        bool sameparent(int u,int v){
            return findUParent(u)==findUParent(v);
        }
        void unionbysize(int u,int v){
            if(sameparent(u,v))return;
            int Pu=findUParent(u);
            int Pv=findUParent(v);
            if(s[Pu]>s[Pv]){
                s[Pu]+=s[Pv];
                parent[Pv]=Pu;
            }else{
                s[Pv]+=s[Pu];
                parent[Pu]=Pv;
            }
        }
};
class Solution {
public:
    int node(int row,int col, int n){
        return (row*n)+col;
    }
    int swimInWater(vector<vector<int>>& grid) {
        unordered_map<int,pair<int,int>>mp;
        int n=grid.size();
        DSU ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[grid[i][j]]={i,j};
            }
        }
        int drow[]={0,1,0,-1};
        int dcol[]={1,0,-1,0};
        for(int t=0;t<n*n;t++){
            int row=mp[t].first;
            int col=mp[t].second;
            for(int i=0;i<4;i++){
                int r=row+drow[i];
                int c=col+dcol[i];
                if(r>=0 && c>=0 && r<n && c<n && grid[r][c]<t){
                    ds.unionbysize(node(row,col,n),node(r,c,n));        
                }
            }
            if(ds.findUParent(node(0,0,n))==ds.findUParent(node(n-1,n-1,n))){
                return t;
            }
        }
        return -1;
    }
};
