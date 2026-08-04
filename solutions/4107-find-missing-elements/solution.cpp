class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        vector<bool>lookup(100,false);
        for(const auto& i : nums){
            maxi=max(i,maxi);
            mini=min(i,mini);
            lookup[i]=true;
        }
        vector<int>ans;
        for(int i=mini;i<maxi;i++){
            if(lookup[i]==false){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
