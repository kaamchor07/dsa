class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned int>v(amount+1,0);
        v[0]=1;
        // for(const auto& i : coins){
        //     v[i]=1;
        // }
        for(const auto& c : coins){
            for(int i=1;i<v.size();i++){    
                if(i-c>=0){
                    v[i]+=v[i-c];
                }
            }
        }
        return v[amount];
    }
};
