class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_set<char>hash;
        for(const auto& i : s){
            hash.insert(i);
        }
        int n=s.size();
        int maxi=0;
        for(const auto& i : hash){
            int left=0;
            int temp=0;
            for(int right=0;right<n;right++){
            if(temp==k && s[right]!=i){
                if(s[left]!=i){
                    left++;
                }else{
                    while(s[left]==i){
                        left++;
                    }
                    left++;
                }
            }else{
                if(s[right]!=i){
                    temp++;
                }
                maxi=max(maxi,right-left+1);
            }
        }
        }
        return maxi;
    }
};
