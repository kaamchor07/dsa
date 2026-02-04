class Solution {
public:
    static bool comp(pair<char,int>&a,pair<char,int>&b){
        return a.second>b.second;
    }
    string frequencySort(string s) {
        int n=s.size();
        string ans="";
        unordered_map<char,int>hash;
        for(int i=0;i<n;i++){
            hash[s[i]]++;
        }
        vector<pair<char,int>>v;
        for(auto &i:hash){
            v.push_back(i);
        }
        sort(v.begin(),v.end(),comp);
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].second;j++){
                ans+=v[i].first;
            }
        }
        return ans;
        
    }
    
};
