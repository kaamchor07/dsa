class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int high=n;
        int low=0;
        int mid;
        int skipped;
        while(high>low){
            mid=low+(high-low)/2;
            skipped=arr[mid]-mid-1;
            if(skipped<k){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        return (k+low);
    };
};
