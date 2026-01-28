class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int high=0;
        int low=0;
        for(int i=0;i<n;i++){
            high=high+weights[i];
            if(weights[i]>low){
                low=weights[i];
            }
        }
        int mid;
        while(high>=low){
            mid=low+(high-low)/2;
            int d=0;
            int sum=0;
            for(int i=0;i<n;i++){
                if(sum+weights[i]<=mid){
                    sum=sum+weights[i];
                }else{
                    sum=weights[i];
                    d++;
                }
            }
            d++;
            if(d>days){
                low=mid+1;
            }else{
                high=mid-1;
            }
            

        }
        return low;
    }
};
