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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int rowmax=-1;
        int colmax=-1;
        unordered_map<int,int>mp;
        for(const auto& i : stones){
            rowmax=max(rowmax,i[0]);
            colmax=max(colmax,i[1]);
        }
        DSU ds(rowmax+colmax+2);
        for(const auto& i : stones){
            int row=i[0];
            int col=i[1]+rowmax+1;
            mp[row]=1;
            mp[col]=1;
            ds.unionbysize(row,col);
        }
        int comp=0;
        for(const auto& i : mp){
            if(ds.findUParent(i.first)==i.first){
                comp++;
            }
        }
        return n-comp;


    }
};
