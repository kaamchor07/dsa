class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        long long int p=(long long)k*m;
        if(p>n){
            return -1;
        }
        int high=bloomDay[0];
        for(int i=0;i<n;i++){
            if(bloomDay[i]>high){
                high=bloomDay[i];
            }
        }
        int low=1;
        int mid;
        while(high>=low){
            mid=low+(high-low)/2;
            int fl=0;
            int bo=0;
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=mid){
                    fl++;
                }else{
                    fl=0;
                }
                if(fl==k){
                    bo++;
                    fl=0;
                }
            }
            if(bo<m){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low;
    }
};
