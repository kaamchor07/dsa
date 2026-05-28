class Solution {
private:
    void makegrid(vector<int>&v1,vector<vector<int>>&g1,int currsum,int nelements,int index){
        if(index==v1.size()){
            g1[nelements].push_back(currsum);
            return;
        }
        makegrid(v1,g1,currsum+v1[index],nelements+1,index+1);
        makegrid(v1,g1,currsum,nelements,index+1);
    }
    int binarysearch(vector<int>&v,int&target){
        int low=0;
        int high=v.size()-1;
        int mid;
        int floor=-1;
        while(high>=low){
            mid=low+(high-low)/2;
            if(v[mid]>target){
                high=mid-1;
            }else{
                low=mid+1;
                floor=mid;
            }
        }
        if (floor == -1) return v[0];
        if(floor+1<=v.size()-1 && abs(target-v[floor])>abs(target-v[floor+1])){
            return v[floor+1];
        }
        return v[floor];
    }
public:
    int minimumDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>v1;
        vector<int>v2;
        vector<vector<int>>g1((n/2)+1);
        vector<vector<int>>g2((n/2)+1);
        for(int i=0;i<n;i++){
            if(i<n/2){v1.push_back(nums[i]);
            }else{
                v2.push_back(nums[i]);
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int target=sum/2;
        makegrid(v1,g1,0,0,0);
        makegrid(v2,g2,0,0,0);
        // for(auto& i : g1){
        //     sort(i.begin(),i.end());
        // }
        for(auto& i : g2){
            sort(i.begin(),i.end());
        }
        int mini=INT_MAX;
        for(int i=0;i<g1.size();i++){
            int m=g1[i].size();
            for(int j=0;j<m;j++){
                int f=target-g1[i][j];
                mini=min(mini,abs(sum-2*(g1[i][j]+binarysearch(g2[n/2-i],f))));
            }
        }
        return mini;
    }
};
