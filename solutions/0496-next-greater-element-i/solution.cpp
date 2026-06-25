class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int>ans;
        unordered_map<int,int>next;
        for(int i=n2-1;i>=0;--i){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            next[nums2[i]]=st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }
        for(int num : nums1){
            ans.push_back(next[num]);

        }
        return ans;

    }
};
