class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash(nums.begin(), nums.end());
        hash.reserve(nums.size());
        if(nums.size()==0){
            return 0;
        }
        int maxcount=1;
        for(int num:hash){
            if(hash.find(num-1)==hash.end()){
                int currentnum=num;
                int count=1;
                while(hash.find(currentnum+1)!=hash.end()){
                    count++;
                    currentnum++;
                }
                maxcount=max(count,maxcount);
            }
        }
        return maxcount;

    }
};
