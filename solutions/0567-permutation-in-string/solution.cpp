class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>s1count;
        unordered_map<char,int>s2count;
        if(s1.length()>s2.length())return false;
        for(int i=0;i<s1.length();i++){
            s1count[s1[i]]++;
            s2count[s2[i]]++;
        }
        if(s1count==s2count)return true;
        int left=0;
        for(int right=s1.length();right<s2.length();right++){
            s2count[s2[right]]++;
            s2count[s2[left]]--;
            if(s2count[s2[left]]==0){
                s2count.erase(s2[left]);
            }
            left++;
            if(s1count==s2count){
                return true;
            }
        }
        return false;
    }
};
