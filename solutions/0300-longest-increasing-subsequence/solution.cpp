class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>tails;
        for(auto x : nums){
            auto it=lower_bound(tails.begin(),tails.end(),x);
            if(it==tails.end()){
                tails.push_back(x);
            }else{
                *it=x;
            }
        }

        return tails.size();
    }
};
