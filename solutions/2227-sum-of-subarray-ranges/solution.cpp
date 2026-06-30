class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<int>st;
        int n=nums.size();
        vector<int>leftmin(n);
        vector<int>rightmin(n);
        vector<int>leftmax(n);
        vector<int>rightmax(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            leftmin[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            rightmin[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            leftmax[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) { 
                st.pop();
            }
            rightmax[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        long long summax=0,summin=0;
        for(int i=0;i<n;i++){
            long long maxcount=(long long)(i-leftmax[i])*(rightmax[i]-i);
            long long mincount=(long long)(i-leftmin[i])*(rightmin[i]-i);
            summax+=maxcount*nums[i];
            summin+=mincount*nums[i];
        }   
        return summax-summin;
    }
};
