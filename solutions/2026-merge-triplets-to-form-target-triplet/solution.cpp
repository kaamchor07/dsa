class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int>ans(3,0);
        for(const auto& i : triplets){
            if(i[0]<=target[0] && i[1]<=target[1] && i[2]<=target[2]){
                ans[0]=max(ans[0],i[0]);
                ans[1]=max(ans[1],i[1]);
                ans[2]=max(ans[2],i[2]);
            }
            if(ans==target)return true;
        }
        return false;
    }
};
