class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(const string& str :strs){
            string sorted=str;
            sort(sorted.begin(),sorted.end());
            mp[sorted].push_back(str);
        }
        vector<vector<string>>res;
        for(auto& pair:mp){
            res.push_back(pair.second);
        }
        return res;
    }
};
