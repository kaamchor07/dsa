class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int n=s.size();
        int right=0;
        int ans=0;
        int maxi=0;
        unordered_set<char>hash;
        while(left<n && right<n){
            if(hash.find(s[right])==hash.end()){
                hash.insert(s[right]);
                ans++;
                right++;
                maxi=max(ans,maxi);
            }else{
                while(left<n && right<n && s[left]!=s[right]){
                    hash.erase(s[left]);
                    left++;
                    ans--;
                }
                hash.erase(s[left]);
                left++;
                ans--;
            }
        }
        return maxi;   
    }
};
