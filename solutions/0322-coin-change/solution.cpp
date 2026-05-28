class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>v(amount+1,-1);
        v[0]=0;
        for(int i=1;i<v.size();i++){
            long long temp=LLONG_MAX;
            for(const auto& c : coins){
                if(i-c>=0 && v[i-c]!=-1){
                    temp=min(temp,static_cast<long long>(v[i-c]+1));
                }
            }
            if(temp==LLONG_MAX){
                v[i]=-1;
            }else{
                v[i]=temp;
            }
        }
        return v[amount];
    }
};
