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
private:
    int node(int row,int col,int n){
        return (row*n)+col;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DSU ds(n*n);
        vector<pair<int,int>>zeros;
        vector<pair<int,int>>ones;
        int drow[]={0,1,0,-1};
        int dcol[]={1,0,-1,0};
        int w=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    zeros.push_back({i,j});
                }else{
                    for(int k=0;k<4;k++){
                        int r=i+drow[k];
                        int c=j+dcol[k];
                        if(r>=0 && c>=0 && r<n && c<n && grid[r][c]==1){
                            ds.unionbysize(node(i,j,n),node(r,c,n));
                        }
                    }
                    ones.push_back({i,j});
                }
            }
        }
        if(zeros.size()==0)return n*n;
        unordered_map<int,int>mp; //parent name,size
        for(const auto& i : ones){
            int row=i.first;
            int col=i.second;
            int p=ds.findUParent(node(row,col,n));
            mp[p]++;
        }
        for(const auto& i : zeros){
            int row=i.first;
            int col=i.second;
            int temp=1;
            unordered_set<int>t;
            for(int k=0;k<4;k++){
                int r=row+drow[k];
                int c=col+dcol[k];
                if(r>=0 && c>=0 && r<n && c<n && grid[r][c]==1){
                    auto it=mp.find(ds.findUParent(node(r,c,n)));
                    if(t.find(it->first)==t.end()){
                        temp+=it->second;
                        t.insert(it->first);
                    }
                }
            }
            w=max(w,temp);
        }
        return w;
    }
};
