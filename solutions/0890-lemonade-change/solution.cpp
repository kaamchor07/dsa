class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int>change; //denomination, number of notes
        change[5]=0;
        change[10]=0;
        change[20]=0;
        for(const auto& i : bills){
            if(i==5){
                change[5]++;
            }else if(i==10){
                change[10]++;
                change[5]--;
                if(change.at(5)<0){
                    return false;
                }
            }else{
                if(change.at(10)>0){
                    change[10]--;
                    change[5]--;
                }else{
                    change[5]-=3;
                }
                if(change[5]<0) return false;
            }
        }
        return true;
    }
};
