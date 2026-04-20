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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>mp;
        int n=accounts.size();
        DSU ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                auto it=mp.find(accounts[i][j]);
                if(it==mp.end()){
                    mp[accounts[i][j]]=i;
                }else{
                    ds.unionbysize(it->second,i);
                }
            }
        }
        vector<vector<string>>mergedmail(n);
        for(int i=0;i<n;i++){
            mergedmail[i].push_back(accounts[i][0]);
        }
        vector<vector<string>>ans;
        for(const auto& i : mp){
            string mail=i.first;
            int parent=ds.findUParent(i.second);
            mergedmail[parent].push_back(mail);
        }
        for(const auto& i : mergedmail){
            if(i.size()==1)continue;
            vector<string>temp=i;
            sort(++temp.begin(),temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
};
