class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int num : nums){
            m[num]++;
        }
        vector<vector<int>>buckets(nums.size()+1);
        for(auto [num,freq] : m){
            buckets[freq].push_back(num);
        }
        vector<int>res;
        for(int i=buckets.size()-1;i>=0;i--){
            for(int num : buckets[i]){
                res.push_back(num);
                if(k==res.size())return res;
            }
        }
        return {};
    }
};
