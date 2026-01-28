class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int high=piles[0];
        for(int i=0;i<n;i++){
            if(piles[i]>high){
                high=piles[i];
            }
        }
        int low=1;
        int mid;
        while(high>=low){
            mid=low+(high-low)/2;
            long long hours=0;
            for(int i=0;i<n;i++){
                hours=hours+((piles[i]-1)/mid +1);
            }
            if(hours<=h){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};
